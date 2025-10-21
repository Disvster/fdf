/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 22:21:41 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/21 22:26:37 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static int	check_sep(char const c, char *sep)
{
	int	i;

	i = 0;
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

static size_t	count_letters_fdf(char const *s, char *c, char **p_s)
{
	size_t	letters;

	letters = 0;
	while (check_sep(*s, c) && *s)
	{
		letters++;
		s++;
	}
	*p_s = (char *)s;
	return (letters);
}

size_t	count_words_fdf(char const *s, char *sep)
{
	size_t	cw;

	cw = 0;
	while (*s)
	{
		while (check_sep(*s, sep) && *s)
			s++;
		if (*s)
			cw++;
		while (!check_sep(*s, sep) && *s)
			s++;
	}
	return (cw);
}

char	**ft_split_fdf(char const *s, char *c)
{
	char	**save;
	char	**split;
	size_t	words;
	size_t	letters;

	words = count_words_fdf(s, c);
	split = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!split)
		return (NULL);
	save = split;
	while (*s)
	{
		while (!(check_sep(*s, c)) && *s)
			s++;
		if (*s)
		{
			letters = count_letters_fdf(s, c, (char **)&s);
			*split = ft_substr(s - letters, 0, letters);
			if (!*split)
				return (free_split(save));
			split++;
		}
	}
	return (save);
}
