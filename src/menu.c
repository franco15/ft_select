/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 20:41:55 by lfranco-          #+#    #+#             */
/*   Updated: 2017/09/18 20:42:00 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_how_to_ft_select(void)
{
	ft_printfcolor("\n%s%s%s %s%s %s%s%s%s%s%s%s%s%s\n", "H",
(rand() % (97 + 1 - 91) + 91), "O", (rand() % (97 + 1 - 91) + 91), "W",
(rand() % (97 + 1 - 91) + 91), "T", (rand() % (97 + 1 - 91) + 91), "O",
(rand() % (97 + 1 - 91) + 91), "F", (rand() % (97 + 1 - 91) + 91), "T",
(rand() % (97 + 1 - 91) + 91), "_", (rand() % (97 + 1 - 91) + 91), "S",
(rand() % (97 + 1 - 91) + 91), "E", (rand() % (97 + 1 - 91) + 91), "L",
(rand() % (97 + 1 - 91) + 91), "E", (rand() % (97 + 1 - 91) + 91), "C",
(rand() % (97 + 1 - 91) + 91), "T", (rand() % (97 + 1 - 91) + 91));
}

static void	print_instructions(void)
{
	int	i;

	print_how_to_ft_select();
	i = (rand() % (96 + 1 - 91) + 91);
	ft_printfcolor("\n%s              | %s\n",
	"key", i, "what do", i - 60);
	ft_printf("-----------------|-------------\n");
	i = (rand() % (96 + 1 - 91) + 91);
	ft_printfcolor("%s           | %s\n", "arrows", i, "move cursor", i - 60);
	i = (rand() % (96 + 1 - 91) + 91);
	ft_printfcolor("%s            | %s\n", "space", i, "select item", i - 60);
	i = (rand() % (96 + 1 - 91) + 91);
	ft_printfcolor("%s/%s | %s\n", "delete", i, "backspace", i,
		"erase item", i - 60);
	i = (rand() % (96 + 1 - 91) + 91);
	ft_printfcolor("%s             | %s\n", "menu", i,
		"enter/quit menu", i - 60);
	i = (rand() % (96 + 1 - 91) + 91);
	ft_printfcolor("%s            | %s\n", "enter", i,
		"exit and return selected items", i - 60);
	i = (rand() % (96 + 1 - 91) + 91);
	ft_printfcolor("%s              | %s\n", "esc", i, "exit program", i - 60);
}

static void	print_header(void)
{
	ft_printfcolor("%s"
, " ______ ______   ______  ______  __      ______  ______  ______  \n"
, (rand() % (96 + 1 - 91) + 91));
	ft_printfcolor("%s"
, "/\\  ___/\\__  _/  \\  ___\\/\\  ___\\/\\ \\    /\\  ___\\/\\  ___\\/\\\
__  _\\ \n", (rand() % (96 + 1 - 91) + 91));
	ft_printfcolor("%s"
, "\\ \\  __\\/_/\\ \\    \\___  \\ \\  __\\  \\ \\___ \\ \\  __\
\\ \\ \\___\\/_/\\ \\/ \n", (rand() % (96 + 1 - 91) + 91));
	ft_printfcolor("%s"
, " \\ \\_\\    \\ \\_\\ /  \\_____\\ \\_____\\ \\_____ \\ \\_____\
\\\\_____\\ \\ \\_\\ \n", (rand() % (96 + 1 - 91) + 91));
	ft_printfcolor("%s\n\n", "  \\/_/     \\/_/  \
\\/_____/\\/_____/\\/_____/\\/_____/\\/_____/   \\/_/\n",
(rand() % (96 + 1 - 91) + 91));
}

void		ft_menu(t_clect *t)
{
	ft_clearscreen(t->row);
	if (t->row > 18 && t->col > 64)
	{
		print_header();
		print_instructions();
	}
	else
		ft_printfcolor("%s\n", "no cabe menu :v", 31);
}
