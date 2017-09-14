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

// static void	validate_win(t_clect *t)
// {
// 	int	i;
//
// 	i = 0;
// 	while (i < t->row)
// 		if (t->av1[i])
// 			i++;
// 	if (i == t->row && t->av1[i])
// 	{
// 		printf("no cabe\n");
// 	}
// 	else
// 	{
// 		i = 0;
// 		while (i < t->row)
// 			printf("%s\n", t->av1[i++]);
// 	}
// }

void	check_win(int signum)
{
	int i;
	char	**tmp;
	t_clect	*t;
	struct winsize win;

	t = get_clect(0);
	signum++;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &win);
	t->row = win.ws_row;
	t->col = win.ws_col;
	ft_clearscreen(t->row);
	// validate_win(t);
	if (t->av1)
	{
		tmp = t->av1;
		for (i = 0; tmp[i]; i++)
			printf("%s\n", tmp[i]);
	}
}
