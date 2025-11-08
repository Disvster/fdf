/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 03:49:53 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/14 19:47:13 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!f || !s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void	ft_rot13(unsigned int i, char *c)
{
	if ((*c >= 'a' && *c <= 'm') || (*c >= 'A' && *c <= 'M'))
		*c += 13;
	else if ((*c >= 'n' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
		*c -= 13;
}

int	main(void)
{
	char	str[] = "felipe";

	ft_striteri(str, (*ft_rot13));
	printf("%s\n", str);
	return (0);
}*/
