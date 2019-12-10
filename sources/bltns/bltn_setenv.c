/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltn_setenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:46:16 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/10 17:21:30 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bltn.h"

static void	free_spl_here(char **args)
{
	size_t	i;

	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
}

static int	setenv_error(char ***str, int errcode)
{
	free_spl_here(*str);
	if (errcode == 1488)
		return (sys_perror("setenv: '=' - bad input", 2, 0));
	return (errcode);
}

int			bltn_setenv(char **args, ENV *env)
{
	t_avln	*node;
	int		i;
	char	**spl;

	i = 0;
	while (args[++i])
	{
		spl = ft_strsplit(args[i], '=');
		if (!spl[0])
			return (setenv_error(&spl, 1488));
		if (!spl[1] && (spl[1] = ft_strdup("")))
			spl[2] = NULL;
		if (ft_avl_search(env->locals, spl[0]) != 0)
			return (setenv_error(&spl, 242));
		else
		{
			if (!(node = ft_avl_node(spl[0], spl[1], ft_strlen(spl[1]) + 1)))
				return (setenv_error(&spl, 210));
			if (ft_avl_set(env->globals, node) == -1)
				return (setenv_error(&spl, 210));
		}
		free_spl_here(spl);
	}
	return (0);
}
