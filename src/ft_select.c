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
	tcsetattr(0, TCSADRAIN, &t->term);
}

int		main(int ac, char **av)
{
	t_clect	t;
	int i;
	char	**tmp;

	(void)ac;
	(void)av;
	start_term(&t);
	if (av[1])
	{
		tmp = &av[1];
		for (i = 0; tmp[i]; i++)
			printf("%s\n", tmp[i]);
	}
	printf("smn\n");
	return (0);
}
