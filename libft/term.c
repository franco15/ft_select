/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 20:02:31 by coco              #+#    #+#             */
/*   Updated: 2017/09/15 20:02:32 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	ft_termcmd(char *s)
{
	if (!s)
		return ;
	ft_putstr_fd(tgetstr(s, NULL), 2);
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

size_t	ft_max_len(char **s)
{
	int		i;
	int		t;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if ((t = ft_strlen(s[i++])) > len)
			len = t;
	}
	return (len);
}
