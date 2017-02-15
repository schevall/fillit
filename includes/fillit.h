/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:53:30 by schevall          #+#    #+#             */
/*   Updated: 2016/12/07 12:16:45 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define ERROR {write(1, "error\n", 6);exit(EXIT_FAILURE);}

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_piece
{
	t_point		point[4];
	int			name;
}				t_piece;

typedef struct	s_tetri
{
	t_piece		piece[26];
	int			nb_of_piece;
	int			side;
}				t_tetri;

int				check_input(char *input);
t_tetri			*save_input_into_tetri(char *input);
char			*ft_strnew(size_t n);
int				tryadd_piece(char *sol, t_tetri *list, int count, int pos);
int				remove_piece(char *sol, t_tetri *list, int count, int pos);
char			*solve_tetri(t_tetri *list);

#endif
