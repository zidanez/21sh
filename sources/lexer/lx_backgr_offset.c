/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_backgr_offset.c                                 :+:      :+:    :+:   */
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

short		is_flow(t_tk_type type)
{
	if (type == TK_WHILE || type == TK_UNTIL || type == TK_FOR)
		return (1);
	return (0);
}

static void	all_to_backgr(t_dlist **token, t_dlist *backgr)
{
	t_dlist *first;

	first = token[0];
	first->prev = backgr;
	backgr->next = first;
	backgr->prev = NULL;
	token[0] = backgr;
	token[1]->next = NULL;
}

static void	to_backgr(t_dlist *t_list, t_dlist *backgr)
{
	t_dlist *tmp;

	tmp = t_list->next;
	t_list->next = backgr;
	backgr->prev = t_list;
	backgr->next = tmp;
	if (tmp && tmp->prev)
		tmp->prev = backgr;
}

short		stop_point(t_tk_type type)
{
	if (type != TK_SEP && type != TK_BCKR_PS && type != TK_ARSHLOCH)
		return (0);
	return (1);
}

t_tk_type	make_offset(t_dlist **token, t_tk_type type)
{
	t_dlist *t_list;
	t_dlist *backgr;

	make_token(token, NULL, type);
	t_list = token[1]->prev;
	backgr = token[1];
	while (t_list && !stop_point(TOK_TYPE) && t_list->prev)
	{
		if (TOK_TYPE == TK_FI)
			t_list = skip_if_script(t_list);
		else if (TOK_TYPE == TK_DONE)
			t_list = skip_done_script(t_list);
		else if (TOK_TYPE == TK_FEND)
			t_list = skip_function(t_list);
		t_list = (t_list->prev) ? t_list->prev : t_list;
	}
	token[1] = (token[1] == token[0]) ? backgr : backgr->prev;
	if (!t_list || !t_list->prev)
		all_to_backgr(token, backgr);
	else
		to_backgr(t_list, backgr);
	make_token(token, NULL, TK_ARSHLOCH);
	return (TK_BCKR_PS);
}
