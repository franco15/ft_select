/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 20:13:26 by coco              #+#    #+#             */
/*   Updated: 2017/09/13 20:13:27 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_termcmd(char *s)
{
	if (!s)
		return ;
	ft_putstr_fd(tgetstr(s, NULL), 2);
}

t_clect	*get_clect(t_clect *t)
{
	static	t_clect *tt = NULL;

	if (t)
		tt = t;
	return (tt);
}

void	ft_clearscreen(int rows)
{
	while (--rows >= 0)
	{
		ft_cursor_goto(0, rows);
		ft_termcmd("dl");
	}
}

void	ft_cursor_goto(int x, int y)
{
	char *str1;
	char *str2;

	if ((str1 = tgetstr("cm", NULL)) != NULL)
	{
		if ((str2 = tgoto(str1, x, y)) != NULL)
			ft_putstr_fd(str2, 2);
	}
}
