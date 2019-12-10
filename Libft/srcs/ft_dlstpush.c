/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:20:53 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:44:53 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlstpush(t_dlist **dlst, t_dlist *nlst)
{
	t_dlist		*it;

	if (!dlst || !nlst)
		return ;
	if (!(it = *dlst))
	{
		*dlst = nlst;
		return ;
	}
	while (it->next)
		it = it->next;
	it->next = nlst;
	nlst->prev = it;
}
