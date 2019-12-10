/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_checkers_3.c                                    :+:      :+:    :+:   */
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

short	back_ps_check(t_dlist *t_list)
{
	t_tk_type	type;

	while (t_list && t_list->content)
	{
		while (t_list && TOK_TYPE != TK_ARSHLOCH)
		{
			type = (TOK_TYPE == TK_EMPTY) ? type : TOK_TYPE;
			t_list = t_list->next;
		}
		if (t_list && (type == TK_SEP || type == TK_AND ||
		type == TK_OR || type == TK_PIPE || type == TK_BCKR_PS))
			return (0);
		if (t_list)
			t_list = t_list->next;
		while (t_list && TOK_TYPE == TK_EMPTY)
			t_list = t_list->next;
		if (!t_list)
			return (1);
		else if (TOK_TYPE != TK_SEP)
			return (0);
		t_list = t_list->next;
	}
	return (1);
}

short	tok_follw(t_dlist *t_list)
{
	if (!t_list || !t_list->next)
		return (0);
	t_list = t_list->next;
	while (t_list && TOK_TYPE == TK_EMPTY)
		t_list = t_list->next;
	if (!t_list || is_sep_token(TOK_TYPE))
		return (0);
	return (1);
}

short	n_after_n(char *prev_sep, char sep)
{
	if (!prev_sep || !sep)
		return (0);
	else if (*prev_sep == '\n' && sep == '\n')
		return (1);
	return (0);
}

short	check_sep_cond(t_dlist *t_list, t_tk_type type)
{
	if (!t_list && type == TK_BCKR_PS)
		return (0);
	if (t_list && !t_list->next && TOK_TYPE == TK_BCKR_PS)
		return (0);
	if (t_list && is_sep_token(TOK_TYPE) && is_sep_token((type)))
		return (0);
	return (1);
}

short	seps_check(t_dlist *t_list)
{
	short	flag;

	flag = 0;
	while (t_list)
	{
		while (t_list && TOK_VALUE && *TOK_VALUE == '\n')
		{
			flag = 0;
			t_list = t_list->next;
		}
		while (t_list && TOK_TYPE == TK_EMPTY)
			t_list = t_list->next;
		if (t_list && is_sep_token(TOK_TYPE) && TOK_TYPE != TK_BCKR_PS)
		{
			if (!flag)
				return (0);
			flag = 0;
		}
		else if (t_list && TOK_TYPE == TK_BCKR_PS && !tok_follw(t_list))
			return (0);
		else
			flag = 1;
		t_list = (t_list) ? t_list->next : t_list;
	}
	return (1);
}
