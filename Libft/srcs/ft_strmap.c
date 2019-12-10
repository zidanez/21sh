/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:37:32 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:47:51 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t			size;
	unsigned int	i;
	char			*map;

	map = 0;
	if (s)
	{
		size = ft_strlen(s);
		map = (char *)malloc(sizeof(char) * (size + 1));
		if (f && map)
		{
			i = 0;
			while (i < size)
			{
				map[i] = (*f)(s[i]);
				i++;
			}
			map[i] = 0;
		}
	}
	return (map);
}
