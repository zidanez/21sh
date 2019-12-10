/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstrget.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:33:53 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:44:55 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist		*ft_dlstrget(t_dlist *cdlst, size_t ind)
{
	while (ind-- && cdlst)
		cdlst = cdlst->prev;
	return (cdlst);
}
