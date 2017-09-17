/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 01:56:48 by coco              #+#    #+#             */
/*   Updated: 2017/09/14 01:56:49 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	validate_win(t_clect *t)
{
	int	i;

	i = t->ac / t->row;
	if (t->ac % t->row)
		i += 1;
	return ((i * t->max) < t->col);
}

static void	put_thing(t_clect *t, char *s, int cursor)
{
	if (cursor == t->cursor)
		ft_termcmd("us");
	if (t->choisi[cursor])
		ft_termcmd("so");
	ft_putstr_fd(s, 2);
	ft_termcmd("ue");
	ft_termcmd("se");
	ft_putcharn_fd(' ', t->max - ft_strlen(s) + 4, 2);

}

static void	print_win(t_clect *t)
{
	int	i;
	int	col;
	int	row;

	row = 0;
	while (row < t->ac && row < t->row)
	{
		col = 0;
		ft_cursor_goto(0, row);
		while ((i = (col++ * t->row) + row) < t->ac)
			put_thing(t, t->av[i], i);
		row++;
	}
}

void	check_win(int signum)
{
	t_clect	*t;
	struct winsize win;

	(void)signum;
	t = get_clect(0);
	ioctl(STDIN_FILENO, TIOCGWINSZ, &win);
	t->row = win.ws_row;
	t->col = win.ws_col;
	ft_clearscreen(t->row);
	if (validate_win(t))
		print_win(t);
	else
		ft_putstr_fd("no cabe :v\n", 2);
		// ft_printfcolor("%s", "no cabe :V", 31);
}
