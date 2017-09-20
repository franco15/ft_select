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

static void	erase_selection(t_clect *t)
{
	int	i;

	i = t->cursor;
	t->ac--;
	free(t->av[i]);
	if (t->choisi[i])
		t->selected--;
	while (t->av[i + 1])
	{
		t->av[i] = t->av[i + 1];
		i++;
	}
	t->av[i] = 0;
	i = t->cursor;
	while (t->choisi[i + 1])
	{
		t->choisi[i] = t->choisi[i + 1];
		i++;
	}
	t->choisi[i] = 0;
	if (t->cursor >= t->ac - 1)
		t->cursor--;
	if (!ft_arrlen((void**)t->av))
		safe_exit(0);
}

void		read_key(t_clect *t)
{
	int		i;
	long	k;

	k = 0;
	while ((read(0, &k, 8)) != 0)
	{
		i = 1;
		if (k == KEY_LEFT || k == KEY_UP || k == KEY_DERE || k == KEY_DOWN)
			arrows(t, k);
		else if (k == KEY_ENTER || k == KEY_DEL || k == KEY_BSP)
			k == KEY_ENTER ? return_choisi(t) : erase_selection(t);
		else if (k == KEY_SPC)
		{
			t->choisi[t->cursor] = t->choisi[t->cursor] == 0 ? 1 : 0;
			t->choisi[t->cursor] == 1 ? t->selected++ : t->selected--;
		}
		else if (k == KEY_M)
			t->menu = t->menu ? 0 : 1;
		else if (k == KEY_ESC || k == KEY_C)
			k == KEY_ESC ? safe_exit(0) : (t->menu = 1);
		else
			i = 0;
		i > 0 ? check_win(0) : 0;
		k = 0;
	}
}
