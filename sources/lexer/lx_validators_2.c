/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_validators_2.c                                  :+:      :+:    :+:   */
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

short	is_tok_deref(char *str)
{
	if (*str == '$' && !is_separator(*(str + 1)))
		return (1);
	if (*str == '~' && (is_separator(*(str + 1)) || *(str + 1) == '/'))
		return (1);
	return (0);
}

char	*pull_legit_math(char *s, t_dlist **tok, t_stx **tr)
{
	s = parse_math(s, tok, tr, 0);
	if (!s)
		return (NULL);
	while (*s == ')' || !is_sep_no_space(*s))
		s = (*s == '\\') ? s + 2 : ++s;
	if (*s != ';' && *s != '\n')
		return (NULL);
	return (parse_sep(s, tok, 0));
}

short	validate_envar(char *str)
{
	if (ft_isdigit(*str) || !(ft_isalpha(*str) || *str == '_'))
		return (0);
	return (1);
}

short	following_pipe(t_dlist *t_list)
{
	if (!t_list->content || (!t_list->prev && TOK_TYPE != TK_PIPE))
		return (0);
	while (t_list && TOK_TYPE == TK_EMPTY)
		t_list = t_list->prev;
	if (t_list && TOK_TYPE == TK_PIPE)
		return (1);
	return (0);
}

short	validate_var(char *varname)
{
	char *const	reserved = "0123456789_!?#$*";
	short		i;

	i = 0;
	if (ft_strlen(varname) == 1)
	{
		while (reserved[i])
		{
			if (*(varname) == reserved[i])
				return (0);
			i++;
		}
	}
	while (*varname)
	{
		if (!ft_isalnum(*varname) && *varname != '_')
			return (0);
		varname++;
	}
	return (1);
}
