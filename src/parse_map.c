/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:43:35 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/03 17:27:33 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

t_data	parse_map(char *file_name)
{
	t_point	*points;
	t_map	map_data;
	t_data	data;
	int		map_fd;

	map_fd = open(file_name, O_RDONLY);
	if (map_fd == -1)
		exit (error_exit(map_fd));
	map_data = map_init_data(map_fd);
	close(map_fd);
	points = ft_calloc(sizeof(t_point), map_data.points_total);
	if (!points)
		exit (error_exit(map_fd));
	map_fd = open(file_name, O_RDONLY);
	data.map = map_data;
	data.points = points;
	map_read_data(&data, map_fd);
	set_points_color(&data);
	print_map(&data);// HACK: db
	close(map_fd);
	return (data);
}

t_map	map_init_data(int fd)
{
	t_map	map;
	char	*line;

	map.width = 0;
	map.height = 0;
	line = get_next_line(fd);
	if (!line)
		exit (error_exit(fd));
	map.width = count_words_fdf(line, " \n");
	while (line)
	{
		map.height++;
		ft_printf("%s", line);// HACK: db
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map.points_total = map.width * map.height;
	return (map);
}
	// ft_printf("x = %d\n", map.width);// HACK: db
	// ft_printf("y = %d\n", map.height);// HACK: db
	// ft_printf("%s", line);// HACK: db
	// ft_printf("x = %d\n", map.width);// HACK: db
	// ft_printf("limit = %d\n", map.width / 2);// HACK: db
	// ft_printf("y = %d\n", map.height);// HACK: db

void	map_read_data(t_data *data, int fd)
{
	int		x;
	int		y;
	int		i;
	char	*buffer;

	if (!data)
		return (free_function(NULL, data), exit(error_exit(fd)));
	i = 0;
	x = -1 * (data->map.width / 2);
	y = -1 * (data->map.height / 2);
	buffer = NULL;
	while (y <= ((data->map.height / 2) + (data->map.height % 2 != 0)))
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		while (x  < ((data->map.width / 2) + (data->map.width % 2 != 0)))
		{
			set_point(data, i, x, buffer);
			data->points[i].y = y;
			x++;
			i++;
		}
		free_function(&buffer, NULL);
		x = -1 * (data->map.width / 2);
		y++;
	}
	free_function(&buffer, NULL);
}
