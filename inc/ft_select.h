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

# define KEY_ENTER	10
# define KEY_ESC	27
# define KEY_SPC	32
# define KEY_M		109
# define KEY_BSP	127
# define KEY_LEFT	4479771
# define KEY_UP		4283163
# define KEY_DERE	4414235
# define KEY_DOWN	4348699
# define KEY_DEL	2117294875

typedef struct		s_clect
{
	int				ac;
	int				row;
	int				col;
	int				max;
	int				cursor;
	int				*choisi;
	int				selected;
	char			**av;
	struct termios	term;
}					t_clect;

/*
** ft_select.c
*/
int		main(int ac, char **av);
void	start_term(t_clect *t);

/*
** keys.c
*/
void	read_key(t_clect *t);

/*
** menu.c
*/
int		ft_menu(t_clect *t);

/*
** signals.c
*/
void	safe_exit(int signum);
void	ft_signals(void);

/*
** utils.c
*/
t_clect	*get_clect(t_clect *t);

/*
** win.c
*/
void	check_win(int signum);
void	return_choisi(t_clect *t);

#endif
