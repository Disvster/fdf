/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 04:07:54 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/07 20:09:57 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	chr;
	size_t			i;

	i = 0;
	temp = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n > i)
	{
		if (temp[i] == chr)
			return ((void *)&temp[i]);
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
int	main(int argc, char *argv[])
{
	char	str[] = "arara felipe azul";
	char	*result;
	char	*OG;

	OG = memchr(str, 'f', 6);
	result = ft_memchr(str, 'f', 6);
	if (OG == NULL)
		printf("N/A\n");
	else
		printf("found at position: %ld\n", OG - str);
	if (result == NULL)
		printf("N/A\n", OG - str);
	else
		printf("found at position: %ld\n", OG - str);

//	OF = memchr(str, 'f', 7);
//	result = ft_memchr(str, 'f', 7);
//	if (OG == NULL)
//		printf("N/A\n");
//	else
//		printf("found at position: %ld\n", OG - str);
//	if (result == NULL)
//		printf("N/A\n", OG - str);
//	else
//		printf("found at position: %ld\n", OG - str);	
	return (0);
}*/
