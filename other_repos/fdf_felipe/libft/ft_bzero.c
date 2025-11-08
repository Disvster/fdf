/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:38:29 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/08 21:59:08 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*b_zero;

	i = 0;
	b_zero = s;
	while (i < n)
	{
		b_zero[i] = '\0';
		i++;
	}
}
/*
#include <string.h>

int	main(int argc, char *argv[])
{
	char	pass[10] = "felipe";
	char	mypass[10] = "felipe";
	int	i;
	size_t	n = ft_strlen(pass);

	i = 0;
	while (i < n)
	{
		printf("pass[%d]: %c\n", i, pass[i]);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	bzero(pass, (n - 2));
	while (i < n)
	{
		printf("OG function: pass[%d]%c\n", i, pass[i]);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	ft_bzero(mypass, (n - 2));
	while (i < n)
	{
		printf("MY function: pass[%d]%c\n", i, mypass[i]);
		i++;
	}
	return (0);
}*/
