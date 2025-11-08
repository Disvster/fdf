/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 06:03:24 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/07 21:09:00 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
#define SIZE 10
int	main(int argc, char *argv[])
{
	char	dst[0];

	dst[0] = '\0';
	(void) argc;
	printf("the string is: %s\n%zu\n", dst, ft_strlcpy(dst, argv[1], SIZE));
	return (0);
}*/
