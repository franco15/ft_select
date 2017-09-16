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

static void	start_term(t_clect *t)
{
	int		i;
	char	*env;

	if (!(env = getenv("TERM")))
		ft_error("check 'TERM' environment");
	if (!(i = tgetent(NULL, env)))
		ft_error("did not gotent");
	if (tcgetattr(0, &t->term))
		ft_error("did not gotattr");
	t->term.c_lflag &= ~(ICANON | ECHO);
	t->term.c_cc[VMIN] = 1;
	t->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &t->term))
		ft_error("did not setattr");
	ft_termcmd("ti");
	ft_termcmd("vi");
}

void	set_t(t_clect *t, int ac, char **av)
{
	t->ncols = ft_max_len(&av[1]);
	t->av = av + 1;
	t->ac = ac - 1;
}

int		main(int ac, char **av)
{
	t_clect	t;

	(void)av;
	if (ac < 2)
		ft_error("No arguments");
	ft_signals();
	set_t(&t, ac, av);
	get_clect(&t);
	start_term(&t);
	check_win(0);
	read_key(&t);
	return (0);
}
