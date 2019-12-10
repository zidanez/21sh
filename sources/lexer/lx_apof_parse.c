/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_apof_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bomanyte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 00:53:18 by bomanyte          #+#    #+#             */
/*   Updated: 2019/12/09 18:29:47 by bomanyte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_req.h"
#include "sh_token.h"
#include "sh_tokenizer.h"

int			expr_was_last(t_dlist *token_list)
{
	if (token_list && token_list->content)
		if (TOK_TYPE == TK_EXPR || TOK_TYPE == TK_FILENAME)
			return (1);
	return (0);
}

void		merge_into_deref(t_dlist *token_list)
{
	while (token_list)
	{
		if (token_list->content && (TOK_TYPE == TK_DEREF || TOK_TYPE == TK_NAME))
		{
			token_list = token_list->next;
			while (token_list && (TOK_TYPE == TK_EXPR))
			{
				TOK_TYPE = TK_NAME;
				token_list = token_list->next;
			}
		}
		else
			token_list = token_list->next;
	}
}

void		merge_into_expr(t_dlist	*token_list, t_dlist **tok)
{
	t_dlist	*next;
	t_dlist	*current;
	char	*tmp;

	while (token_list)
	{
		if (token_list->content && (TOK_TYPE == TK_EXPR || TOK_TYPE == TK_FILENAME))
		{
			current = token_list;
			token_list = token_list->next;
			if (token_list && (TOK_TYPE == TK_EXPR || TOK_TYPE == TK_FILENAME))
			{
				tmp = ft_strjoin(((t_tok *)(current->content))->value, TOK_VALUE);
				free(((t_tok *)(current->content))->value);
				((t_tok *)(current->content))->value = tmp;
				next = token_list->next;
				ft_dlstrmelem(&token_list);
				tok[1] = next ? tok[1] : current;
				token_list = current;
			}
		}
		else
			token_list = token_list->next;
	}
}

// void		merge_expr(t_dlist	*last_token, t_dlist **tok)
// {
// 	t_dlist	*token_list;
// 	t_dlist	*prev;
// 	t_dlist	*current;
// 	char	*tmp;

// 	current = tok[1];
// 	while (current && current != last_token)
// 	{
// 		token_list = current;
// 		current = current->prev;
// 	}
// 	if (current && TOK_TYPE != TK_DEREF && TOK_VALUE)
// 	{
// 		tmp = ft_strjoin(((t_tok *)(current->content))->value, TOK_VALUE);
// 		free(((t_tok *)(current->content))->value);
// 		((t_tok *)(current->content))->value = tmp;
// 		prev = token_list->next;
// 		// current->next = prev;
// 		// if (prev)
// 		// 	prev->prev = current;
// 		ft_dlstrmelem(&token_list);
// 		tok[1] = prev ? tok[1] : current;
// 	}
// }

static char	*pull_apof(char *str, t_dlist **tok)
{
	size_t	j;

	j = 0;
	if (*str && *str == '\'')
	{
		++str;
		while (*str && *str != '\'')
		{
			if (*str == '\\')
			{
				str++;
				j++;
			}
			str++;
			j++;
		}
		yes_we_can(str, tok, APOF, j);
	}
	return (parse_sep(++str, tok, 0));
}

char		*parse_apofs(char *str, t_dlist **tok, t_stx **tree, short i)
{
	int		flag;
	t_dlist	*last_token;

	if (!is_q(*str))
		if (!(str = parse_comm(str, tok, tree, '\'')))
			return (NULL);
	flag = expr_was_last(tok[1]) ? 1 : i;
	flag = deref_was_last(tok[1]) ? 2 : flag;
	last_token = tok[1];
	str = pull_apof(str, tok);
	if (flag)
	{
		merge_into_expr(last_token, tok);
		if (flag == 2)
			merge_into_deref(tok[0]);
	}
	return (str);
}