/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_load_save_rdr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:08:26 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/10 16:05:52 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "sh_readline.h"
#include "sys_tools/sys_tools.h"
#include "sys_tools/sys_errors.h"

void		exe_redir_save420(t_dlist *redrs)
{
	REDIRECT	*rdr;

	while (redrs)
	{
		rdr = (REDIRECT *)redrs->content;
		dup2(rdr->fdl, rdr->fdl + SYS_REDR_OFFST);
		redrs = redrs->next;
	}
}

void		exe_redir_load420(t_dlist *redrs)
{
	REDIRECT	*rdr;

	while (redrs)
	{
		rdr = (REDIRECT *)redrs->content;
		dup2(rdr->fdl + SYS_REDR_OFFST, rdr->fdl);
		close(rdr->fdl + SYS_REDR_OFFST);
		redrs = redrs->next;
	}
}
