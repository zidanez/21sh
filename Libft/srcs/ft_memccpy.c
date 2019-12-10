/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:07:16 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:45:59 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*ptr;
	size_t	len;

	if ((ptr = ft_memchr(src, c, n)))
	{
		len = ptr - src + 1;
		ft_memcpy(dst, src, len);
		return (dst + len);
	}
	ft_memcpy(dst, src, n);
	return (0);
}
