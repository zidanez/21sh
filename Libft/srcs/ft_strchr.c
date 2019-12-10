/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 08:25:09 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:47:11 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"

char	*ft_strchr(const char *str, int ch)
{
	return ((char *)ft_memchr((char *)str, ch, (ft_strlen(str) + 1)));
}
