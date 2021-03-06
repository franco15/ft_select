/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 20:13:38 by coco              #+#    #+#             */
/*   Updated: 2017/09/13 20:13:39 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		safe_exit(int signum)
{
	t_clect	*t;

	(void)signum;
	t = get_clect(0);
	ft_memdel((void**)&t->choisi);
	ft_memdel((void**)t->av);
	ft_clearscreen(t->row);
	t->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, TCSANOW, &t->term);
	ft_termcmd("te");
	ft_termcmd("ve");
	exit(1);
}

void		suspend_term(int signum)
{
	t_clect	*t;
	char	tmp[3];

	(void)signum;
	t = get_clect(0);
	ft_clearscreen(t->row);
	t->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, TCSANOW, &t->term);
	ft_termcmd("te");
	ft_termcmd("ve");
	signal(SIGTSTP, SIG_DFL);
	tmp[0] = t->term.c_cc[VSUSP];
	tmp[1] = '\n';
	tmp[2] = '\0';
	ioctl(0, TIOCSTI, &tmp);
}

void		continue_term(int signum)
{
	t_clect	*t;

	(void)signum;
	t = get_clect(0);
	start_term(t);
	ft_signals();
	check_win(0);
}

void		ft_signals(void)
{
	signal(SIGHUP, safe_exit);
	signal(SIGINT, safe_exit);
	signal(SIGQUIT, safe_exit);
	signal(SIGILL, safe_exit);
	signal(SIGTRAP, safe_exit);
	signal(SIGABRT, safe_exit);
	signal(SIGEMT, safe_exit);
	signal(SIGFPE, safe_exit);
	signal(SIGBUS, safe_exit);
	signal(SIGSEGV, safe_exit);
	signal(SIGSYS, safe_exit);
	signal(SIGPIPE, safe_exit);
	signal(SIGALRM, safe_exit);
	signal(SIGTERM, safe_exit);
	signal(SIGTTIN, safe_exit);
	signal(SIGTTOU, safe_exit);
	signal(SIGXCPU, safe_exit);
	signal(SIGXFSZ, safe_exit);
	signal(SIGVTALRM, safe_exit);
	signal(SIGPROF, safe_exit);
	signal(SIGUSR1, safe_exit);
	signal(SIGUSR2, safe_exit);
	signal(SIGTSTP, suspend_term);
	signal(SIGCONT, continue_term);
	signal(SIGWINCH, check_win);
}
