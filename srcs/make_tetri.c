/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:44:43 by schevall          #+#    #+#             */
/*   Updated: 2016/12/07 11:40:22 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void		ft_do_pt(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

static t_piece	save_piece_into_tetri(char *buf, int index)
{
	int			i;
	int			n;
	t_point		start;
	t_piece		piece;

	i = 0;
	n = 0;
	start.x = -1;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (start.x == -1)
			{
				ft_do_pt(&(start), i % 5, i / 5);
				ft_do_pt(&(piece.point[n]), 0, 0);
			}
			else
				ft_do_pt(&(piece.point[n]), i % 5 - start.x, i / 5 - start.y);
			n++;
		}
		i++;
	}
	piece.name = 'A' + index;
	return (piece);
}

t_tetri			*save_input_into_tetri(char *input)
{
	t_tetri		*tetri;
	int			fd;
	char		*buf;
	int			index;
	int			ret[2];

	buf = ft_strnew(21);
	if (!(tetri = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	fd = open(input, O_RDONLY);
	index = 0;
	while ((ret[0] = read(fd, buf, 21)))
	{
		if (check_input(buf) == 1 || ret[0] < 20)
			ERROR;
		tetri->piece[index] = save_piece_into_tetri(buf, index);
		tetri->nb_of_piece = ++index;
		ret[1] = ret[0];
	}
	if ((ret[0] == 0 && tetri->nb_of_piece == 0) || ret[1] != 20)
		ERROR;
	close(fd);
	free(buf);
	return (tetri);
}
