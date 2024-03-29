/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_cutters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 00:53:18 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/12/10 16:15:55 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_req.h"
#include "sh_token.h"
#include "sh_tokenizer.h"

char	*join_mirr(char *new, char *tmp, char *add)
{
	if (new)
	{
		tmp = ft_strjoin(new, tmp);
		free(new);
		return (tmp);
	}
	else
		new = ft_strjoin(add, tmp);
	return (new);
}

char	*cook_mirr(char *new, char *add)
{
	char	*tmp;

	tmp = ft_strjoin(new, "\\");
	free(new);
	new = tmp;
	tmp = ft_strjoin(new, add);
	free(new);
	return (tmp);
}

char	*cut_mirr(char **splitted)
{
	char	*new;
	char	*tmp;
	size_t	i;

	i = 1;
	new = NULL;
	if (!splitted[i] && splitted[0])
		new = pull_single(splitted[0]);
	while (splitted[i])
	{
		if (splitted[i] && splitted[i][0] == '\n')
			tmp = &splitted[i][1];
		else
			tmp = splitted[i];
		new = join_mirr(new, tmp, splitted[i - 1]);
		i++;
	}
	return (new);
}

size_t	cut_quots(char *str)
{
	int		counter;
	size_t	len;

	counter = 0;
	len = 0;
	while (!(is_q(str[len])))
		len = (str[len] == '\\') ? len + 2 : ++len;
	while (is_q(str[len++]))
		counter++;
	while (counter && str[len] && !is_sep_no_space(str[len]))
	{
		if (is_q(str[len]))
			--counter;
		len = (str[len] == '\\') ? len + 2 : ++len;
	}
	return (len - 2);
}

size_t	cut_brackets(char *str)
{
	int		counter;
	size_t	len;
	size_t	br;

	counter = 0;
	len = 0;
	while (str[len] != '(')
		len = (str[len] == '\\') ? len + 2 : ++len;
	while (str[len++] == '(')
		counter++;
	br = 2;
	while (counter && str[len])
	{
		if (str[len] == '(')
			++counter;
		else if (str[len] == ')')
			--counter;
		len = (str[len] == '\\') ? len + 2 : ++len;
	}
	return (len - (br * 2));
}
