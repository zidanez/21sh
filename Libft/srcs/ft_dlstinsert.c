/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:36:40 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:44:48 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void		ft_dlstinsert(t_dlist *insrt, t_dlist *prv, t_dlist *nxt)
{
	if (prv)
	{
		insrt->prev = prv;
		prv->next = insrt;
	}
	if (nxt)
	{
		insrt->next = nxt;
		nxt->prev = insrt;
	}
}
