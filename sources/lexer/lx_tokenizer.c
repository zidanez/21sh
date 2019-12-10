/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_tokenizer.c                                     :+:      :+:    :+:   */
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

char	*g_last_input;

void	global_init(void)
{
	g_parse_err = -1;
	g_syntax_err = -1;
	g_input_nover = -1;
}

short	get_tokens(char *str, t_dlist **t_list)
{
	static t_stx	*tree[13];
	t_tk_type		choice;
	short			code;

	code = 0;
	if (!tree[0])
		tree_init(tree);
	global_init();
	if (!(*str) || (code = input_finished(str)) != 1)
		return (code);
	while (*str)
	{
		choice = find_token(tree, str);
		if (!(str = block_pass(choice, str, t_list, tree)))
			return (clear_tokens(t_list, 1));
	}
	if (t_list[0]->content && !back_ps_check(t_list[0]))
		return (clear_tokens(t_list, 1));
	if (t_list[0]->content && !(list_ready_to_go(t_list)))
		return (clear_tokens(t_list, 1));
	make_token(t_list, NULL, TK_EOF);
	return (1);
}

t_dlist	**toklst_init(t_dlist **t_list)
{
	if (t_list[0])
		return (t_list);
	t_list[0] = (t_dlist *)malloc(sizeof(t_dlist));
	t_list[0]->next = NULL;
	t_list[0]->content = NULL;
	t_list[0]->prev = NULL;
	t_list[0]->size = 0;
	t_list[1] = t_list[0];
	return (t_list);
}

short	concatenate_str(char **last_input, char *str)
{
	char		*tmp;

	if (!input_no_over_code())
	{
		tmp = *last_input;
		*last_input = ft_strjoin(*last_input, "\n");
		free(tmp);
	}
	tmp = *last_input;
	*last_input = ft_strjoin(*last_input, str);
	free(tmp);
	return (1);
}

short	sh_tokenizer(char *str, t_dlist **t_list)
{
	extern char	*g_last_input;
	char		*tmp;
	short		i;

	if (g_intr == 2 && (g_input_nover = -1))
		g_last_input ? ft_strdel(&g_last_input) : 0;
	if ((!str || !(*str)) && INO == -1)
		return (0);
	t_list = toklst_init(t_list);
	if (g_last_input && concatenate_str(&g_last_input, str))
		tmp = g_last_input;
	else
		tmp = str;
	if ((i = get_tokens(tmp, t_list)) != 1)
	{
		if (i < 0 && g_last_input)
			g_last_input = null_last_input(&g_last_input);
		if (!i)
			g_last_input = g_last_input ? g_last_input : ft_strdup(tmp);
		return (i ? -1 : 0);
	}
	if (g_last_input)
		g_last_input = null_last_input(&g_last_input);
	return (1);
}
