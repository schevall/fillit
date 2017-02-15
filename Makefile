# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 12:59:12 by schevall          #+#    #+#              #
#    Updated: 2016/12/01 16:05:37 by schevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =		./srcs/main.c\
			./srcs/check_input.c\
			./srcs/ft_strnew.c\
			./srcs/make_tetri.c\
			./srcs/solve_tetri.c\
			./srcs/add_or_remove_piece.c\

OFILES =	main.o\
			check_input.o\
			ft_strnew.o\
			make_tetri.o\
			solve_tetri.o\
			add_or_remove_piece.o\

INCLUDES = ./includes/

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
		gcc -I $(INCLUDE) $(FLAGS) -c $(SRCS)
		gcc $(OFILES) -o $(NAME)

clean :
		/bin/rm -f $(OFILES)

fclean : clean
		/bin/rm -f $(NAME)

re : fclean all
