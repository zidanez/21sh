/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_sigs_dfl_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 07:55:01 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/10 16:32:34 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

extern int		g_intr;

void			sighand(int s)
{
	g_intr = s;
}

void			sys_sig_dfl(void)
{
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
}

void			sys_sig_init(void)
{
	struct sigaction	siga;
	sigset_t			smask;

	sigemptyset(&smask);
	sigaddset(&smask, SIGINT);
	siga.__sigaction_u = ((union __sigaction_u)(sighand));
	siga.sa_mask = smask;
	siga.sa_flags = 0;
	sigaction(SIGINT, &siga, 0);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
}
