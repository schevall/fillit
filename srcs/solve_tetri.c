/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:53:11 by schevall          #+#    #+#             */
/*   Updated: 2016/12/07 11:46:36 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char		*make_tab(t_tetri *list)
{
	int			pos;
	int			side;
	char		*sol;

	side = list->side;
	if (!(sol = (char*)malloc(sizeof(char) * side * side + 1)))
		return (NULL);
	pos = 0;
	while (pos < (side * side))
	{
		sol[pos] = '.';
		pos++;
	}
	sol[pos] = '\0';
	return (sol);
}

static int		is_side_possible(char *sol, t_tetri *list, int count, int pos)
{
	if (count == list->nb_of_piece)
		return (1);
	while (sol[pos])
	{
		if (sol[pos] == '.')
		{
			if (tryadd_piece(sol, list, count, pos))
			{
				if (is_side_possible(sol, list, count + 1, 0) == 1)
					return (1);
				remove_piece(sol, list, count, pos);
			}
		}
		pos++;
	}
	return (0);
}

char			*solve_tetri(t_tetri *list)
{
	char		*sol;

	sol = make_tab(list);
	if (is_side_possible(sol, list, 0, 0))
	{
		return (sol);
	}
	else
	{
		++list->side;
		free(sol);
		return (solve_tetri(list));
	}
}
