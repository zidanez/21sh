/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_cleaners.c                                      :+:      :+:    :+:   */
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

void			*ft_arrmemdel(void **ap)
{
	unsigned char	**ptr;
	int				i;
	int				j;

	i = 0;
	j = 0;
	ptr = (unsigned char **)ap;
	while (ptr[j])
	{
		free(ptr[j]);
		j++;
	}
	free(ap);
	return (NULL);
}

static t_dlist	*rm_void_token(t_dlist *t_list)
{
	t_dlist	*tmp_next;
	t_dlist	*tmp_prev;

	tmp_next = t_list->next;
	tmp_prev = t_list->prev;
	t_list->next = NULL;
	del_tokens(t_list);
	tmp_prev->next = tmp_next;
	tmp_next->prev = tmp_next ? tmp_prev : tmp_next->prev;
	t_list = tmp_prev;
	return (t_list);
}

static void		get_rid_of_void(t_dlist *t_list)
{
	while (t_list)
	{
		if (TOK_TYPE == TK_EMPTY)
		{
			t_list = t_list->next;
			if (t_list && TOK_TYPE == TK_EMPTY)
				t_list = rm_void_token(t_list);
			else
			{
				if (t_list)
					t_list = t_list->next;
			}
		}
		else
			t_list = t_list->next;
	}
}

static void		trim_separators(t_dlist *t_list)
{
	while (t_list)
	{
		if (TOK_TYPE == TK_SEP)
		{
			free(TOK_VALUE);
			TOK_VALUE = NULL;
		}
		t_list = t_list->next;
	}
}

short			list_ready_to_go(t_dlist **t_list)
{
	t_dlist	*start;

	exec_on(t_list[0]);
	get_rid_of_void(t_list[0]);
	merge_into_expr(t_list[0], t_list);
	merge_into_name(t_list[0], t_list);
	if (!seps_check(t_list[0]) || !args_check(t_list[0]))
		return (0);
	trim_separators(t_list[0]);
	start = t_list[0];
	while (start->next)
		start = start->next;
	t_list[1] = start;
	return (1);
}
