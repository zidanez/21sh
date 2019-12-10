/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:46:22 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:47:18 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t		len;

	len = ft_strlen(src);
	ft_memcpy(dst, src, len);
	dst[len] = 0;
	return (dst);
}
