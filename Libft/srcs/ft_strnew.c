/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:51:18 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:48:08 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == ((size_t)0) - 1)
		return (0);
	str = (char *)ft_memalloc(size + 1);
	return (str);
}
