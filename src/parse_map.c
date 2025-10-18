/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:43:35 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/18 03:40:05 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	print_map(t_data *data);

t_map	map_data_init(int fd)
{
	t_map	map;
	char	*line;

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
	// if (!line)// NOTE: se o gnl falhar dou exit do prog
	// 	exit (1);
	// if (line)
	// 	free(line);
	map.points_total = map.width * map.height;
	return (map);
}

void	*map_read_data(t_data *data, int fd)// FIX: size
{
	int		x;
	int		y;
	int		i;
	char	*buffer;

	if (!data)
		return (NULL);// NOTE: maybe a free func below
	i = 0;
	x = -1 * (data->map->width / 2);
	y = -1 * (data->map->height / 2);
	buffer = NULL;
	while (y <= (data->map->height / 2))
	{
		buffer = get_next_line(fd);// FIX: 1b still reachable here by gnl->free_stash->substr
		if (!buffer)
			return (free_buffer(buffer));
		while (x <= (data->map->width / 2))
		{
			set_point(data, i, x, buffer);
			data->points[i].y = y;
			x++;
			i++;
		}
		free_buffer(buffer);
		x = -1 * (data->map->width / 2);
		y++;
	}
	return (data);
}

void	parse_map(char *file_name)
{
	t_point	*points;
	t_map	map_data;
	t_data	data;
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
	map_fd = open(file_name, O_RDONLY);
	data.map = &map_data;
	data.points = points;
	map_read_data(&data, map_fd);
	print_map(&data);
	close(map_fd);
	free(points);// WARNING:dont forget to free points
}

void	print_map(t_data *data)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	while (y < data->map->height)
	{
		while (x < data->map->width)
		{
			ft_printf(" %d,%d,%d ",//,%s) ",
			 data->points[i].x, data->points[i].y, data->points[i].z);//, data->points[i].color);
			x++;
			i++;
			if (x == data->map->width)
				ft_printf("\n");
		}
		x = 0;
		y++;
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	parse_map(av[1]);
}
// passar map_size numa funcao exterior
// na main{
	// open(av[1], O_RDONLY);
// }
