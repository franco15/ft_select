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

void	return_choisi(t_clect *t)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	t->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, TCSANOW, &t->term);
	ft_termcmd("te");
	ft_termcmd("ve");
	ft_clearscreen(t->row);
	while (t->av[i])
	{
		if (t->choisi[i])
		{
			printf("%s", t->av[i]);
			if (++j == t->selected)
				break ;
			printf(" ");
		}
		i++;
	}
	printf("\n");
	ft_memdel((void**)&t->choisi);
	ft_memdel((void**)t->av);
	exit(1);
}
