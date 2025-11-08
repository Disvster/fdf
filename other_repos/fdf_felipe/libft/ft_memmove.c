/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:39:01 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/15 22:09:00 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if ((!dest && !src) || n < 0)
		return (dest);
	if (dest > src)
	{
		while (n--)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
/*
#include <string.h>
int	main(void)
{					src  abcdef
                    
					dest defghi
	char	str[] = "abc defghi j";

	char	*dest = str + 3;

	char	*src = str;

	n = 5;

	return (0);
}*/
