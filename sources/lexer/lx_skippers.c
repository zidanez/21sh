/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_skippers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 00:53:18 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/12/10 16:42:40 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_req.h"
#include "sh_token.h"
#include "sh_tokenizer.h"

t_dlist	*skip_if_script(t_dlist *t_list)
{
	size_t	counter;

	counter = 0;
	if (TOK_TYPE == TK_FI)
		counter++;
	t_list = t_list->prev;
	while (t_list->prev && counter)
	{
		if (TOK_TYPE == TK_FI)
			counter++;
		else if (TOK_TYPE == TK_IF)
			counter--;
		t_list = t_list->prev;
	}
	return (t_list);
}

t_dlist	*skip_done_script(t_dlist *t_list)
{
	size_t	counter;

	counter = 0;
	if (TOK_TYPE == TK_DONE)
		counter++;
	t_list = t_list->prev;
	while (t_list->prev && counter)
	{
		if (TOK_TYPE == TK_DONE)
			counter++;
		else if (is_flow(TOK_TYPE))
			counter--;
		t_list = t_list->prev;
	}
	return (t_list);
}

t_dlist	*skip_function(t_dlist *t_list)
{
	t_list = t_list->prev;
	while (t_list->prev && TOK_TYPE != TK_FUNCTION)
		t_list = t_list->prev;
	return (t_list);
}

size_t	skip_field(char *str, char skip)
{
	size_t	jump;

	jump = 1;
	while (str[jump] && str[jump] != skip)
	{
		if (str[jump] == '\\' && str[++jump])
			jump++;
		else
			jump++;
	}
	if (!str[jump])
		return (0);
	return (jump);
}

char	*skip_comment(char *str)
{
	while (*str && *str != '\n')
		str++;
	return (str);
}
