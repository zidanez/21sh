/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 02:22:32 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:47:54 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				map[i] = (*f)(i, s[i]);
				i++;
			}
			map[i] = 0;
		}
	}
	return (map);
}
