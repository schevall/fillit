/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:44:43 by schevall          #+#    #+#             */
/*   Updated: 2016/12/07 11:46:39 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static	size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	check_char(char *input)
{
	size_t		i;
	size_t		count;
	size_t		ctrl;

	i = 0;
	count = 0;
	ctrl = 0;
	while (i < 21)
	{
		if (input[i] == '#')
			count++;
		if (input[i] == '.' || input[i] == '\n' || input[i] == '\0')
			ctrl++;
		i++;
	}
	if (count != 4)
		return (1);
	if (count + ctrl != 21)
		return (1);
	return (0);
}

static size_t	check_if_square(char *input)
{
	size_t		i;

	i = 0;
	while (i < 20)
	{
		if (input[i] == '\n')
		{
			if ((i - 4) % 5)
				return (1);
		}
		i++;
	}
	return (0);
}

static size_t	check_piece_is_valid(char *input)
{
	size_t		i;
	size_t		friend;

	i = 0;
	friend = 0;
	while (i < 20)
	{
		if (input[i] == '#' && input[i + 1] == '#')
			friend++;
		if (input[i] == '#' && input[i + 5] == '#')
			friend++;
		i++;
	}
	if (friend > 2)
		return (0);
	return (1);
}

int				check_input(char *input)
{
	if (input[20] != '\n' && input[20] != '\0')
		return (1);
	if (ft_strlen(input) < 20)
		return (1);
	if (check_char(input))
		return (1);
	if (check_if_square(input))
		return (1);
	if (check_piece_is_valid(input))
		return (1);
	return (0);
}
