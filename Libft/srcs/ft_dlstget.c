/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:28:54 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:44:45 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist		*ft_dlstget(t_dlist *cdlst, size_t ind)
{
	while (ind-- && cdlst->next)
		cdlst = cdlst->next;
	return (cdlst);
}
