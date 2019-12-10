/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:24:52 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/10 16:06:49 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "parser.h"
#include "sys_tools/sys_errors.h"

t_dlist		*prs_bkgr(ETAB **tab, t_dlist *tokens, ENV *envr)
{
	BCKGR	*bkgr;
	ETAB	*nrow;

	envr = 0;
	if (!(nrow = (ETAB *)ft_dlstnew_cc(0, 0)))
		sys_fatal_memerr("PARSING FAILED");
	if (!(nrow->instruction = ft_memalloc(sizeof(bkgr))))
		sys_fatal_memerr("PARSING FAILED");
	nrow->type = ET_BCKGR;
	bkgr = (BCKGR *)nrow->instruction;
	bkgr->tls = tokens->next;
	tokens = prs_skip_until(tokens, TK_ARSHLOCH);
	ft_dlstpush((t_dlist **)tab, (t_dlist *)nrow);
	return (tokens);
}
