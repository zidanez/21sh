/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 05:38:34 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:45:42 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*del_goal;
	t_list		*iter;

	if (alst && *alst && del)
	{
		iter = *alst;
		while (iter)
		{
			del_goal = iter;
			iter = iter->next;
			ft_lstdelone(&del_goal, del);
		}
		*alst = 0;
	}
}
