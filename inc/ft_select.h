/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:52:43 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/04 18:52:45 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT
# define FT_SELECT

# include "../libft/minilibft.h"
# include <stdio.h>
# include <termios.h>
# include <term.h>

typedef struct		s_clect
{
	struct termios	term;
}					t_clect;

/*
** ft_select.c
*/
int		main(int ac, char **av);

#endif
