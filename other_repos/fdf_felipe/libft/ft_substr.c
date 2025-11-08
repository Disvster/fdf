/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:48:11 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/13 03:46:43 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlenlen(const char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (str[i] && len)
	{
		i++;
		len--;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		sub_len;

	if (!s)
		return (ft_strdup(""));
	sub_len = ft_strlen(s);
	if (sub_len <= start)
		return (ft_strdup(""));
	sub_len = ft_strlenlen(s + start, len);
	sub = malloc(sizeof(*sub) * (sub_len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, sub_len + 1);
	return (sub);
}
/*
int	main(void)
{
	printf("%s\n", ft_substr("hola", 2, 1));
	return (0);
}*/
