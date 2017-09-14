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

	i = 0;
	printf("%d\n", t->row);
	while (i < t->row)
		if (t->av1[i])
			i++;
	if (i == t->row && t->av1[i])
		return (0);
	return (1);
}

static void	print_win(t_clect *t)
{
	int	i;

	i = 0;
	ft_clearscreen(t->row);
	while (i < t->row)
		printf("%s\n", t->av1[i++]);
}

void	check_win(int signum)
{
	// int i;
	// char	**tmp;
	t_clect	*t;
	struct winsize win;

	t = get_clect(0);
	signum++;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &win);
	t->row = win.ws_row;
	t->col = win.ws_col;
	if (validate_win(t))
		print_win(t);
	else
	{
		ft_clearscreen(t->row);
		ft_printfcolor("%s", "no cabe :V", 31);
	}
	// if (t->av1)
	// {
	// 	tmp = t->av1;
	// 	for (i = 0; tmp[i]; i++)
	// 		printf("%s\n", tmp[i]);
	// }
}
