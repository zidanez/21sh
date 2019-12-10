/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 00:53:18 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/10 16:42:40 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_req.h"
#include "sh_token.h"
#include "sh_tokenizer.h"
#include "bltn_math/math_hidden.h"

t_dlist	*prepare_op_stack(t_dlist *ops, t_tk_type op)
{
	t_dlist		*tmp;

	if (op != OUT_BR)
	{
		tmp = ops;
		ops = (ops && ops->next) ? ops->next : NULL;
	}
	else
		tmp = ops ? ops->prev : NULL;
	del_tokens(ops);
	if (tmp)
	{
		tmp->next = NULL;
		while (tmp->prev)
			tmp = tmp->prev;
	}
	return (tmp);
}

void	del_tokens(t_dlist *token)
{
	t_dlist *t_list;

	while (token)
	{
		t_list = token;
		token = token->next;
		if (t_list->content && TOK_VALUE)
			free(TOK_VALUE);
		free(t_list->content);
		free(t_list);
	}
}

t_dlist	*clean_op_stack(t_dlist *ops)
{
	del_tokens(ops);
	ops = NULL;
	return (ops);
}

t_dlist	*lst_to_end(t_dlist *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

size_t	count_dlist(t_dlist *list)
{
	size_t	len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
