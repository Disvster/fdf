/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:07:13 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/11 03:08:34 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		if (!t1[i])
			return (0);
		i++;
	}
	return (0);
}
/*
#include <string.h>
int	main(int argc, char *argv[])
{
	(void) argc;

	printf("mine: %d\n", ft_strncmp("\x12de\xad", "\x12\x02", 6));
	printf("OG: %d\n", ft_strncmp("\x12\xffad", "\x12\x02", 6));
	return (0);
}*/
