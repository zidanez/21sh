/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 06:29:18 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/10 15:55:50 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stdlib.h>

void	*ft_memdup(void *start, size_t len)
{
	void	*newmem;

	if (!len)
		return (0);
	if ((newmem = malloc(len)))
		ft_memcpy(newmem, start, len);
	return (newmem);
}
