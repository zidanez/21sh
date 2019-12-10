/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_args_check.c                                    :+:      :+:    :+:   */
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

short			input_no_over_code(void)
{
	if (g_input_nover == PRO_SUBSH || g_input_nover == PRO_MATH ||
	g_input_nover == PRO_PIPE
	|| g_input_nover == PRO_AND || g_input_nover == PRO_OR ||
	g_input_nover == PRO_SQU)
		return (1);
	return (0);
}

static short	is_tok_what(t_dlist *t_list, t_tk_type type)
{
	if (type == SEPS)
		if (TOK_TYPE != TK_SEP && TOK_TYPE != TK_OR && TOK_TYPE != TK_AND
		&& TOK_TYPE != TK_PIPE && TOK_TYPE != TK_BCKR_PS &&
		TOK_TYPE != TK_ARSHLOCH)
			return (0);
	if (type == FLOWS)
		if (TOK_TYPE != TK_IF && TOK_TYPE != TK_THEN && TOK_TYPE != TK_WHILE
	&& TOK_TYPE != TK_IN && TOK_TYPE != TK_ELSE && TOK_TYPE != TK_FOR)
			return (0);
	if (type == PROF)
		if (TOK_TYPE != TK_PROF_IN && TOK_TYPE != TK_PROF_OUT &&
		TOK_TYPE != TK_PROC_IN
	&& TOK_TYPE != TK_PROC_OUT)
			return (0);
	return (1);
}

static short	vector_to_left(t_dlist *t_list)
{
	while (t_list && (TOK_TYPE == TK_EMPTY))
		t_list = t_list->prev;
	if (!t_list)
		return (1);
	if (t_list && !is_tok_what(t_list, SEPS) &&
	!is_tok_what(t_list, FLOWS)
	&& TOK_TYPE != TK_DEREF && TOK_TYPE != TK_ASSIGM &&
	TOK_TYPE != TK_FUNCTION &&
	!is_tok_redir(TOK_TYPE, 1) && TOK_TYPE != TK_EXEC &&
	TOK_TYPE != TK_RETURN)
		return (0);
	return (1);
}

static short	vector_to_right(t_dlist *t_list)
{
	while (t_list && (TOK_TYPE == TK_EMPTY))
		t_list = t_list->next;
	if (!t_list)
		return (1);
	if (t_list && !is_tok_what(t_list, SEPS) && TOK_TYPE != TK_IN
	&& !is_tok_redir(TOK_TYPE, 1) && !is_tok_what(t_list, PROF)
	&& TOK_TYPE != TK_FD)
		return (0);
	return (1);
}

short			args_check(t_dlist *t_list)
{
	while (t_list)
	{
		while (t_list && TOK_TYPE == TK_EMPTY)
			t_list = t_list->next;
		if (t_list && (TOK_TYPE == TK_MATH || TOK_TYPE == TK_SUBSH))
		{
			if (!vector_to_left(t_list->prev))
				return (0);
			if (!vector_to_right(t_list->next))
				return (0);
		}
		t_list = t_list ? t_list->next : NULL;
	}
	return (1);
}
