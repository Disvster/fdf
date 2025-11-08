/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:58:37 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/15 22:11:42 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimmable(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		finish;

	if (!s1)
		return (ft_strdup(""));
	start = 0;
	while (ft_trimmable(set, s1[start]))
		start++;
	finish = (ft_strlen(s1) - 1);
	while (ft_trimmable(set, s1[finish]))
		finish--;
	trimmed = ft_substr(s1, start, (finish - start + 1));
	return (trimmed);
}
/*
int	main(int argc, char *argv[])
{
	printf("%s\n", ft_strtrim("hhhhhhh", "h"));
	return (0);
}*/
