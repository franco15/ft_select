/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 02:31:51 by coco              #+#    #+#             */
/*   Updated: 2017/09/14 02:31:52 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	read_key(t_clect *t)
{
	// int		i;
	long	k;

	(void)t;
	k = 0;
	while ((read(0, &k, 8)) != 0)
	{
		// i = 1;
		if (k == KEY_ESC)
			safe_exit(0);
		else if (k == KEY_SPC)
			printf("cols: %d rows: %d ac: %d\n", t->col, t->row, t->ac);
		// else
			// i = 0;
		// (i > 0) ? check_win(0) : 0;
		k = 0;
	}
}
