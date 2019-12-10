/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_substitutors.c                                  :+:      :+:    :+:   */
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

char	*cook_err_msg(char *insertion)
{
	char	*str;
	char	*tmp;

	tmp = ft_strjoin(SIMPERR, insertion);
	str = ft_strjoin(tmp, "' token");
	free(tmp);
	return (str);
}

void	expr_to_value(t_dlist *t_list)
{
	while (t_list && (TOK_TYPE == TK_EMPTY || TOK_TYPE == TK_SEP))
		t_list = t_list->prev;
	while (t_list && (TOK_TYPE != TK_EMPTY && TOK_TYPE != RETURN))
	{
		if (TOK_TYPE == TK_EXPR)
			TOK_TYPE = TK_VALUE;
		t_list = t_list->prev;
	}
}

void	substitute_value(t_dlist *t_list)
{
	while (t_list && TOK_TYPE != TK_ASSIGM)
	{
		if (TOK_TYPE == TK_EXPR)
			TOK_TYPE = TK_VALUE;
		t_list = t_list->prev;
	}
}

void	exec_on(t_dlist *t_list)
{
	while (t_list)
	{
		if (TOK_TYPE == TK_EXPR)
			if (!ft_strcmp(TOK_VALUE, "exec"))
				TOK_TYPE = TK_EXEC;
		t_list = t_list->next;
	}
}
