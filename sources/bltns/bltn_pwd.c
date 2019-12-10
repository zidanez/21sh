/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltn_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:08:20 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/10 16:04:46 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bltn.h"
#include <limits.h>

int			bltn_pwd(char **args, ENV *env)
{
	char	*flgs;
	char	buf[PATH_MAX];

	env = 0;
	flgs = ft_parse_flags(args);
	if (flgs && ft_strrchr(flgs, 'P') != NULL)
	{
		if ((getcwd(buf, sizeof(buf))) < 0)
		{
			ft_putendl(g_pwd->txt);
			return (1);
		}
		ft_putendl(buf);
	}
	else
		ft_putendl(g_pwd->txt);
	return (1);
}
