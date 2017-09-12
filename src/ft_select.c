/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:52:57 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/04 18:52:58 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	set_term(t_clect *t)
{
	char	*ttype;
	char	*term;

	term = 0;
	if (!(ttype = getenv("TERM")))
		ft_error("check 'TERM' environment");
	if (!(tgetent(term, ttype)))
		ft_error("did not gotent");
	if (tcgetattr(0, &t->term))
		ft_error("did not gotattr");
}

int		main(int ac, char **av)
{
	t_clect	t;

	(void)ac;
	(void)av;
	set_term(&t);
	printf("smn\n");
	return (0);
}
