/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 04:11:21 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/14 16:57:32 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122)))
		return (0);
	return (1);
}
/*
#include <ctype.h>
int	main(int argc, char *argv[])
{
//	printf("%d\n", ft_isalpha(argv[1][0]));
//	printf("%d\n", isalpha(argv[1][0]));
	if (isalpha(argv[1][0]))
		printf("arara\n");
	return (0);
}*/
