/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 12:44:26 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:45:06 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void		ft_dlstswap(t_dlist *a, t_dlist *b)
{
	void		*tmpc;
	size_t		tmps;

	if (!a || !b)
		return ;
	tmpc = a->content;
	tmps = a->size;
	a->content = b->content;
	a->size = b->size;
	b->content = tmpc;
	b->size = tmps;
}
