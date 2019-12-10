/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_make_clear.c                                    :+:      :+:    :+:   */
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

short	clear_tokens(t_dlist **tokens, short id)
{
	t_dlist	*t_list;

	if (id)
		unexpected_token(tokens);
	while (*tokens)
	{
		t_list = *tokens;
		*tokens = (*tokens)->next;
		if (t_list->content && TOK_VALUE)
			free(TOK_VALUE);
		free(t_list->content);
		free(t_list);
	}
	tokens[0] = NULL;
	tokens[1] = NULL;
	return (-1);
}

void	next_next_tok(t_dlist **list, char *value, t_tk_type type)
{
	t_tok	token_data;
	t_dlist	*tmp;

	token_data.value = value;
	token_data.type = type;
	tmp = list[1];
	tmp->next = ft_dlstnew(NULL, 0);
	tmp = tmp->next;
	tmp->content = (t_tok *)malloc(sizeof(t_tok));
	*((t_tok *)(tmp->content)) = token_data;
	tmp->next = NULL;
	tmp->prev = list[1];
	list[1] = tmp;
}

void	make_next_tok(t_dlist **list, char *value, t_tk_type type)
{
	t_tok	token_data;
	t_dlist	*tmp;

	token_data.value = value;
	token_data.type = type;
	tmp = list[0];
	tmp->next = ft_dlstnew(NULL, 0);
	tmp->next->content = (t_tok *)malloc(sizeof(t_tok));
	*((t_tok *)(tmp->next->content)) = token_data;
	tmp->next->next = NULL;
	tmp->next->prev = list[0];
	list[1] = tmp->next;
}

void	make_token(t_dlist **list, char *value, t_tk_type type)
{
	t_tok	token_data;

	if (list[0] == list[1] && !list[0]->content)
	{
		token_data.value = value;
		token_data.type = type;
		list[1]->content = (t_tok *)malloc(sizeof(t_tok));
		*((t_tok *)(list[1]->content)) = token_data;
		list[0]->next = NULL;
	}
	else if (list[0] == list[1])
		make_next_tok(list, value, type);
	else
		next_next_tok(list, value, type);
}

char	*null_last_input(char **last_input)
{
	free(*last_input);
	return (NULL);
}
