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

t_map	map_data_init(int fd)
{
	t_map	map;
	char	*line;
	int		x;
	int		y;

	map.width = 0;
	map.height = 0;
	line = get_next_line(fd);
	if (line)
		map.width = count_words(line, ' ');
	while (line)
	{
		map.height++;
		free(line);
		line = get_next_line(fd);
	}
	if (!line)// NOTE: se o gnl falhar dou exit do prog
		exit (1);
	if (line)
		free(line);
	map.points_total = map.width * map.height;
	return (map);
}


t_point	*map_read_data(t_point *points, int width, int height, int fd)
{
	int		x;
	int		y;
	int		z;
	int		i;

	// TODO: fazer um gnl aqui a cada y e um split para cada x, com o split vou obter a height e a color

	if (!points)
		return (NULL);// NOTE: maybe a free func below
	i = 0;
	x = -1 * (width / 2);
	y = -1 * (height / 2);
	while (y < height)
	{
		while (x < height)
		{
			set_point(points + i, x, y);
			x++;
			i++;
		}
		y++;
	}
	return (points);
}

void	parse_map(char *file_name)
{
	t_point	*points;
	t_map	map_data;
	int		map_fd;

	map_fd = open(file_name, O_RDONLY);
	if (map_fd == -1)
	{
		write(2, "File not found!\n", 17);
		return ;// TODO: free function here
	}
	map_data = map_data_init(map_fd);
	close(map_fd);
	points = malloc(sizeof(t_point) * (map_data.points_total));
	if (!points)
		return ;// TODO: free function here
	map_read_data(points, map_data.height, map_data.width, map_fd);
}
// passar map_size numa funcao exterior
// na main{
	// open(av[1], O_RDONLY);
// }
