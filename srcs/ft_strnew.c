/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:07:45 by schevall          #+#    #+#             */
/*   Updated: 2016/12/01 15:40:58 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void			*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*mem;

	i = 0;
	a = (unsigned char)c;
	mem = (unsigned char *)s;
	while (i < n)
	{
		mem[i] = a;
		i++;
	}
	return (mem);
}

static void			ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, 0, n);
}

char				*ft_strnew(size_t n)
{
	char			*str;

	if (!(str = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	if (str)
	{
		ft_bzero(str, n + 1);
		return (str);
	}
	else
		return (NULL);
}
