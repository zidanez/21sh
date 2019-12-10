/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 08:05:56 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:47:08 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"

char	*ft_strccpy(char *dst, const char *src, int c)
{
	char	*ptr;
	size_t	len;

	if ((ptr = ft_strchr(src, c)))
	{
		len = ptr - src + 1;
		ft_memcpy(dst, src, len);
		return (dst + len);
	}
	ft_strcpy(dst, src);
	return (0);
}
