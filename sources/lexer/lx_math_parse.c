/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_math_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 00:53:18 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/12/10 16:17:01 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_req.h"
#include "sh_token.h"
#include "sh_tokenizer.h"

size_t		cut_math_seq(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && (str[i] != ' ' && str[i] != '\t') &&
	!(is_sep_no_space(str[i])))
	{
		if (str[i] == '\\' && (str[i + 1] == ' ' || str[i + 1] == '\t'))
			i += 2;
		i++;
	}
	return (i);
}

char		*pull_math_seq(char *str, t_dlist **tok)
{
	size_t	len;

	len = cut_math_seq(str);
	make_token(tok, pull_token(str, len), TK_MATH);
	str += len;
	return (str);
}

char		*pull_in_brackets(char br, char *str, t_dlist **tok)
{
	size_t	len;

	len = (br == '(') ? cut_brackets(str) : cut_quots(str);
	str += 2;
	make_token(tok, pull_token(str, len), TK_MATH);
	br = (br == '(') ? ')' : br;
	return (skip_brackets(str + len, br));
}

char		*parse_math(char *str, t_dlist **tok, t_stx **tree, short ind)
{
	char	br;

	if (!(*str))
		return (str);
	str = parse_empty(str, 0x0, tok);
	if (*str == '\\')
		return (block_pass(EXPRS, str, tok, tree));
	if (is_token_here(str, "let"))
		str = ft_process_ignore(str, ".let%");
	str = skip_spaces(str);
	br = *str;
	if (br == '(' || br == '\'' || br == '"')
		str = pull_in_brackets(br, str, tok);
	else
		str = pull_math_seq(str, tok);
	return (ind < 0 ? "\0" : str);
}
