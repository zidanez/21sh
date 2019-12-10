/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstunshift.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:13:29 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:45:08 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlstunshift(t_dlist **dlst, t_dlist *nlst)
{
	if (!nlst || !dlst)
		return ;
	nlst->next = *dlst;
	if (*dlst)
		(*dlst)->prev = nlst;
	*dlst = nlst;
}
