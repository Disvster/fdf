/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:03:29 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/09 23:21:28 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*temp2;

	if (!dest && !src)
		return (dest);
	i = 0;
	temp = (unsigned char *)dest;
	temp2 = (unsigned char *)src;
	while (i < n)
	{
		temp[i] = temp2[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
int	main(void)
{
	size_t	n = 0;
	char	a[30] = "fefefefe";
	char	*b = "";
	char	*mem = ft_memcpy(a, b, n);
	char	*memm = memcpy(a, b, n);
	
	printf("mine: %s\n", mem);
	printf("og: %s\n", memm);
	return (0);
}*/
