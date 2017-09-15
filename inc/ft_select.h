/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:52:43 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/04 18:52:45 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT
# define FT_SELECT

# include <term.h>
# include <stdio.h>
# include <signal.h>
# include <termios.h>
# include <sys/ioctl.h>
# include "../libft/minilibft.h"

# define KEY_SPC	32
# define KEY_ESC	27

typedef struct		s_clect
{
	int				row;
	int				col;
	int				ac;
	char			**av;
	struct termios	term;
}					t_clect;

/*
** ft_select.c
*/
int		main(int ac, char **av);

/*
** keys.c
*/
void	read_key(t_clect *t);

/*
** signals.c
*/
void	safe_exit(int signum);
void	ft_signals(void);

/*
** utils.c
*/
void	ft_termcmd(char *s);
t_clect	*get_clect(t_clect *t);
void	ft_clearscreen(int rows);
void	ft_cursor_goto(int x, int y);

/*
** win.c
*/
void	check_win(int signum);

#endif
