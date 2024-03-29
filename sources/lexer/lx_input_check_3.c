/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_input_check_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 00:53:18 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/12/10 16:16:31 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_req.h"
#include "sh_token.h"
#include "sh_tokenizer.h"

short			br_closed_n(char *str, short i)
{
	while (*str)
	{
		if (*str == '\\' && ++str)
			++str;
		else if (*str == '\'' || *str == '\"' || *str == '(' || *str == ')')
			str = br_cls_n(str, &i);
		else
			++str;
	}
	return (i);
}

short			brackets_closed(char *str)
{
	short	times;
	short	math_flag;

	times = br_closed_n(str, 0);
	math_flag = 0;
	if (layer_parse_one("((", str) || layer_parse_one("~((", str))
		math_flag = 1;
	if (times)
	{
		g_parse_err = times < 0 ? PRO_SUBSH : g_parse_err;
		g_input_nover = times > 0 ? PRO_SUBSH : g_input_nover;
		g_input_nover = (times > 0 && math_flag) ? PRO_MATH : g_input_nover;
		return (times > 0 ? 0 : -1);
	}
	return (1);
}

static short	is_and_closed(char *str, size_t size)
{
	if (*(str + size - 1) == '&' && (size - 2) && *(str + size - 2) == '&')
	{
		if ((size - 3) && *(str + size - 2) == '\\')
			return (1);
		return (0);
	}
	return (1);
}

short			input_closed(char *str)
{
	int	size;

	size = ft_strlen(str);
	while (size && (*(str + size - 1) == ' ' || *(str + size - 1) == '\t'))
		--size;
	if (*(str + size - 1) == '|' && (size - 2 >= 0) &&
	*(str + size - 2) != '\\')
	{
		g_input_nover = *(str + size - 2) == '|' ? PRO_OR : PRO_PIPE;
		return (0);
	}
	if (*(str + size - 1) == '\\' && (size - 2 >= 0) &&
	*(str + size - 2) != '\\')
	{
		g_input_nover = PRO_NONE;
		return (0);
	}
	if (!is_and_closed(str, size))
	{
		g_input_nover = PRO_AND;
		return (0);
	}
	return (1);
}

short			are_tokens_here(char *str)
{
	if (is_token_here(str, "while"))
		return (1);
	if (is_token_here(str, "for"))
		return (1);
	if (is_token_here(str, "until"))
		return (1);
	return (0);
}
