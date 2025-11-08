/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 03:19:35 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/14 17:26:39 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	dest_len;

	if (size == 0 && !dst)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	dest_len = ft_strlen(dst);
	if (size <= i)
		return (ft_strlen(src) + size);
	k = 0;
	while (src[k] && (i + 1) < size)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (dest_len + ft_strlen(src));
}
/*
#include <bsd/string.h>
#define SIZE 20
int	main(int argc, char *argv[])
{
	char	a[SIZE] = "felipe";
	char	a2[SIZE] = "felipe";
	char	*b = "arara";

	printf("Mine: %zu\n", ft_strlcat(a2, b, SIZE));
	printf("Mine: %s\n", a);
	printf("Og: %zu\n", strlcat(a, b, SIZE));
	printf("Og: %s\n", a);
	return (0);
}*/
