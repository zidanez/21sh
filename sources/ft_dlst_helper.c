/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 22:45:59 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/10 16:07:54 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include "ft_mem.h"

size_t			ft_dlst_len(t_dlist *lst)
{
	size_t		len;

	len = 0;
	while (lst && ++len)
		lst = lst->next;
	return (len);
}

char			**ft_dlst_to_warr(t_dlist *lst, \
char *(*cnt_cb)(void *, size_t sz))
{
	size_t		len;
	size_t		i;
	char		**warr;

	len = ft_dlst_len(lst);
	i = 0;
	warr = ft_memalloc((len + 1) * sizeof(char *));
	if (!warr)
		return (NULL);
	while (lst)
	{
		warr[i] = cnt_cb(lst->content, lst->size);
		++i;
		lst = lst->next;
	}
	warr[i] = NULL;
	return (warr);
}

char			*callback_dlst_warr(void *cnt, size_t sz)
{
	sz = 0;
	return ((char *)cnt);
}
