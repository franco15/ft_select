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

static void	arrows(t_clect *t, long k)
{
	if (k == KEY_LEFT && (t->cursor - t->row) < t->ac &&
		(t->cursor - t->row) >= 0)
		t->cursor -= t->row;
	else if (k == KEY_UP)
		t->cursor == 0 ? (t->cursor = t->ac - 1) : t->cursor--;
	else if (k == KEY_DERE && (t->cursor + t->row) < t->ac)
		t->cursor += t->row;
	else if (k == KEY_DOWN)
	{
		if (t->cursor == t->ac - 1)
			t->cursor = 0;
		else if (t->cursor < t->ac)
			t->cursor++;
	}
}

void		read_key(t_clect *t)
{
	int		i;
	long	k;

	k = 0;
	while ((read(0, &k, 8)) != 0)
	{
		i = 1;
		printf("%ld\n", k);
		if (k == KEY_LEFT || k == KEY_UP || k == KEY_DERE || k == KEY_DOWN)
			arrows(t, k);
		else if (k == KEY_ENTER)
			return_choisi(t);
		else if (k == KEY_SPC)
			t->choisi[t->cursor] == 0 ? ((t->choisi[t->cursor] = 1) &&
				(t->selected++)) : ((t->choisi[t->cursor] = 0) && (t->selected -= 1));
		// else if (k == KEY_DEL || k == KEY_BSP)
		// 	erase_choisi(t);
		else if (k == KEY_ESC)
			safe_exit(0);
		else
			i = 0;
		(i > 0) ? check_win(0) : 0;
		k = 0;
	}
}
