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

t_clect	*get_clect(t_clect *t)
{
	static	t_clect *tt = NULL;

	if (t)
		tt = t;
	return (tt);
}

void	escape(void)
{
	t_clect	*t;

	t = get_clect(0);
	ft_clearscreen(t->row);
	t->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, TCSANOW, &t->term);
	ft_termcmd("te");
	ft_termcmd("ve");
	exit(3);
}
