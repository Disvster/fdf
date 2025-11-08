/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:26:45 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/09 03:01:56 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <string.h>
int	main(int argc, char *argv[])
{
	char	a[] = "feli";
	char	b[] = "feli";
	int	n = 7;

	(void)argc;
	(void)argv;
	printf("mine: %d\n", ft_memcmp(a, b, n));
	printf("OG: %d\n", memcmp(a, b, n));
	return (0);
}*/
