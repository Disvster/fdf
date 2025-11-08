/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 02:54:59 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/15 22:13:48 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_populate_itoa(char *str, int nbr, int size, int bol_negative)
{
	if (nbr == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	str[size] = '\0';
	while (size > bol_negative)
	{
		str[--size] = (nbr % 10) + '0';
		nbr /= 10;
	}
}

static	int	ft_count(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*itoa;
	int		bol_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digits = ft_count(n);
	itoa = malloc(sizeof(char) * (digits + 1));
	if (!itoa)
		return (NULL);
	bol_negative = 0;
	if (n < 0)
	{
		bol_negative++;
		n = -n;
		itoa[0] = '-';
	}
	ft_populate_itoa(itoa, n, digits, bol_negative);
	return (itoa);
}
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", ft_itoa(ft_atoi(argv[1])));
	return (0);
}*/
