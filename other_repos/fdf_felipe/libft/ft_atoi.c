/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:09:35 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/09 18:14:39 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	soma;
	int	signal;

	if (!(*nptr))
		return (0);
	i = 0;
	soma = 0;
	signal = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signal = -signal;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		soma = nptr[i] - '0' + (soma * 10);
		i++;
	}
	return (soma * signal);
}
/*
int	main(int argc, char *argv[])
{
	printf("%d\n", ft_atoi(argv[1]));
	printf("%d\n", atoi(argv[1]));
	return (0);
}*/
