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

t_clect				*get_clect(t_clect *t)
{
	static	t_clect *tt = NULL;

	if (t)
		tt = t;
	return (tt);
}