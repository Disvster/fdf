/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:43:35 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/13 02:52:58 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	parse_map(t_data *data, char *file_name)
{
	t_point	*points;
	t_map	map_data;
	int		map_fd;

	map_fd = open(file_name, O_RDONLY);
	if (map_fd == -1)
		exit (error_exit(map_fd, NULL));
	map_data = map_init_data(map_fd);
	close(map_fd);
	points = ft_calloc(map_data.points_total, sizeof(t_point));
	if (!points)
		exit (error_exit(map_fd, "Memory Error\n"));
	map_fd = open(file_name, O_RDONLY);
	data->map = map_data;
	data->points = points;
	data->fd = map_fd;
	map_read_data(data, map_fd);
	set_points_color(data);
	close(map_fd);
}

static void	init_map_read(int *i, int *x, int *y, t_map *map)
{
	*i = 0;
	*x = -1 * (map->width / 2);
	*y = -1 * (map->height / 2);
}

void	map_read_data(t_data *data, int fd)
{
	int		x;
	int		y;
	int		i;
	char	*buffer;

	init_map_read(&i, &x, &y, &data->map);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		while (x <= (data->map.width - 1) / 2)
		{
			data->points[i].y = y;
			set_point(data, i, x, buffer);
			x++;
			i++;
		}
		free_function(&buffer, NULL);
		x = -1 * (data->map.width / 2);
		y++;
	}
	free_function(&buffer, NULL);
}

void	set_point(t_data *data, int i, int x, char *buffer)
{
	static char	**xline;
	static int	xi;

	if (!xline)
	{
		xline = ft_split_fdf(buffer, " \n");
		xi = 0;
		if (!xline)
			return (free_function(&buffer, data),
				exit(error_exit(data->fd, "Parsing Error\n")));
	}
	data->points[i].x = x;
	data->points[i].z = ft_atoi(xline[xi]);
	if (ft_strchr(xline[xi], ',') != NULL)
	{
		data->points[i].color = handle_color_code(ft_strchr(xline[xi], ','),
				data);
		if (!data->points[i].color)
			return (free_split(xline), free_function(&buffer, data),
				exit(error_exit(data->fd, "Invalid Color Format\n")));
	}
	xi++;
	if (!xline[xi] || (((ft_abs(x) + i) > data->map.points_total) && data->map.py))
		xline = free_split(xline);
}

t_map	map_init_data(int fd)
{
	t_map	map;
	char	*line;

	ft_bzero(&map, sizeof(t_map));
	line = get_next_line(fd);
	if (!line)
		exit (error_exit(fd, "Memory Error\n"));
	map.width = count_words_fdf(line, " \n");
	while (line)
	{
		map.height++;
		free(line);
		line = get_next_line(fd);
		if (line && (int)count_words_fdf(line, " \n") < map.width)
			map.py += 1;
		if (line && (int)count_words_fdf(line, " \n") > map.width)
			map.width = (int)count_words_fdf(line, " \n");

	}
	free(line);
	map.points_total = map.width * map.height + map.py;
	map.has_color = false;
	return (map);
}
