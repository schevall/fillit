/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:53:11 by schevall          #+#    #+#             */
/*   Updated: 2016/12/01 17:06:01 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		tryadd_piece(char *sol, t_tetri *list, int count, int pos)
{
	int y;
	int x;
	int pt_nb;
	int side;

	pt_nb = 0;
	side = list->side;
	while (pt_nb < 4)
	{
		y = pos / side + list->piece[count].point[pt_nb].y;
		x = pos % side + list->piece[count].point[pt_nb].x;
		if (y >= list->side || x >= list->side ||
				y < 0 || x < 0 || sol[y * side + x] != '.')
			return (0);
		pt_nb++;
	}
	pt_nb = 0;
	while (pt_nb < 4)
	{
		y = pos / side + list->piece[count].point[pt_nb].y;
		x = pos % side + list->piece[count].point[pt_nb].x;
		sol[y * side + x] = list->piece[count].name;
		pt_nb++;
	}
	return (1);
}

int		remove_piece(char *sol, t_tetri *list, int count, int pos)
{
	int	pt_nb;
	int	y;
	int	x;
	int	side;

	pt_nb = 0;
	side = list->side;
	while (pt_nb < 4)
	{
		y = pos / side + list->piece[count].point[pt_nb].y;
		x = pos % side + list->piece[count].point[pt_nb].x;
		sol[y * side + x] = '.';
		pt_nb++;
	}
	return (1);
}
