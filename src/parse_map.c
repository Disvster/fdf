/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:43:35 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/25 01:36:36 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	*info_iso(int fd)
{
	char	*line;
	int		*iso;
	int		x;
	int		y;

	line = get_next_line(fd);
	if (line)
		x = count_words(line, ' ');
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	iso = ft_calloc(sizeof(int), 2);
	iso[0] = x;
	iso[1] = y;
	return (iso);
}// put this info in a struct. then parse the map again to get points in a t_point array
