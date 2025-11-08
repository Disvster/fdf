/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:11:01 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/09 18:25:23 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * size + 1);
	if (!dup)
		return (NULL);
	dup[0] = '\0';
	ft_strlcpy(dup, s, size + 1);
	return (dup);
}
/*
int	main(int argc, char *argv[])
{
	(void) argc;
	printf("Original: %s\nDuplicate: %s\n", argv[1], ft_strdup(argv[1]));
	return (0);
}*/
