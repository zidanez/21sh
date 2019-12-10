/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:50:40 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:44:51 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include "ft_mem.h"
#include <stdlib.h>

t_dlist			*ft_dlstnew(void *cont, size_t sz)
{
	t_dlist		*res;

	if (!(res = (t_dlist *)malloc(sizeof(t_dlist))))
		return (0);
	res->size = 0;
	if (sz || (res->content = 0))
	{
		if (!(res->content = ft_memdup(cont, sz)))
		{
			free(res);
			return (0);
		}
		res->size = sz;
	}
	res->next = 0;
	res->prev = 0;
	return (res);
}

t_dlist			*ft_dlstnew_cc(void *content, size_t size)
{
	t_dlist		*res;

	if (!(res = (t_dlist *)malloc(sizeof(t_dlist))))
		return (0);
	res->size = size;
	res->content = content;
	res->next = 0;
	res->prev = 0;
	return (res);
}
