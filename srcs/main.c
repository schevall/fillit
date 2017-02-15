/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:44:43 by schevall          #+#    #+#             */
/*   Updated: 2016/12/05 15:13:06 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void		size_of_tab(t_tetri *tetri)
{
	int			side;

	side = tetri->nb_of_piece;
	if (side * 4 > side * side)
		side++;
	while (side * 4 < (side - 1) * (side - 1))
		side--;
	tetri->side = side;
}

static void		display_result(char *sol, t_tetri *tetri)
{
	int			pos;

	pos = 0;
	while (sol[pos])
	{
		if (pos != 0 && pos % tetri->side == 0)
			write(1, "\n", 1);
		write(1, &sol[pos], 1);
		pos++;
	}
}

int				main(int ac, char **av)
{
	t_tetri		*tetri;
	char		*sol;

	if (ac != 2)
	{
		write(1, "usage: fillit file_path\n", 24);
		return (0);
	}
	tetri = save_input_into_tetri(av[1]);
	size_of_tab(tetri);
	sol = solve_tetri(tetri);
	display_result(sol, tetri);
	free(tetri);
	free(sol);
	return (0);
}
