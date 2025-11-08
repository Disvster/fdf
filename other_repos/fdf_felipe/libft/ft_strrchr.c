/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:53:09 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/13 03:50:13 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*temp;
	char		ct;
	int			i;

	ct = (char) c;
	temp = (char *)s;
	i = ft_strlen(s);
	if (ct == 0)
		return ((char *)&temp[i]);
	while (0 <= i)
	{
		if (temp[i] == ct)
			return ((char *)&temp[i]);
		i--;
	}
	return (NULL);
}
/*
#include <string.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	printf("mine: %s\n", ft_strrchr(argv[1], argv[2][0] + 1024));
	printf("original: %s\n", strrchr(argv[1], argv[2][0] + 1024));
	return (0);
}*/
