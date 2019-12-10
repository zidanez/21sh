/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr_swpc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 17:13:30 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:43:10 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dstring.h"

DSTRING			*dstr_dstr_swpc(DSTRING *dst, DSTRING *ndst, ssize_t ind)
{
	DSTRING		*res;

	res = dstr_slice(dst, 0, ind);
	if (ndst)
		dstr_insert_dstr(res, ndst, res->strlen);
	else
		dstr_insert_str(res, "", ind);
	return (res);
}

DSTRING			*dstr_str_swpc(DSTRING *dst, char *str, ssize_t ind)
{
	DSTRING		*res;
	DSTRING		*ndst;

	ndst = dstr_new(str);
	res = dstr_slice(dst, 0, ind);
	dstr_insert_dstr(res, ndst, res->strlen);
	dstr_del(&ndst);
	return (res);
}

DSTRING			*dstr_chr_swpc(DSTRING *dst, char ch, ssize_t ind)
{
	DSTRING		*res;
	DSTRING		*ndst;
	char		fake[2];

	fake[0] = ch;
	fake[1] = '\0';
	ndst = dstr_new(fake);
	res = dstr_slice(dst, 0, ind);
	dstr_insert_dstr(res, ndst, res->strlen);
	dstr_del(&ndst);
	return (res);
}
