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

	ft_bzero(&data, sizeof(t_data));
	map_fd = open(file_name, O_RDONLY);
	if (map_fd == -1)
		exit (error_exit(map_fd));
	map_data = map_init_data(map_fd);
	close(map_fd);
	points = ft_calloc(map_data.points_total, sizeof(t_point));
	if (!points)
		exit (error_exit(map_fd));
	map_fd = open(file_name, O_RDONLY);
	data.map = map_data;
	data.points = points;
	data.fd = map_fd;
	map_read_data(&data, map_fd);
	set_points_color(&data);
	close(map_fd);
	return (data);
}

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
		while (x < ((data->map.width / 2) + (data->map.width % 2 != 0)))
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

void	set_point(t_data *data, int i, int x, char *buffer)
{
	static char	**xline;
	int			xi;

	xi = (data->map.width / 2) + x;
	if (!xline)
	{
		xline = ft_split_fdf(buffer, " \n");
		if (!xline)
			return (free_function(&buffer, data), exit(error_exit(data->fd)));
	}
	data->points[i].x = x;
	data->points[i].z = ft_atoi(xline[xi]);
	if (ft_strchr(xline[xi], ',') != NULL)
	{
		data->points[i].color = ft_atoi_base
			(ft_strchr(xline[xi], ',') + 3, "0123456789ABCDEF");
		if (!data->points[i].color)
			return (free_function(&buffer, data), exit(error_exit(data->fd)));
	}
	if (!xline[xi + 1])
	{
		free_split(xline);
		xline = NULL;
	}
}

t_map	map_init_data(int fd)
{
	t_map	map;
	char	*line;

	ft_bzero(&map, sizeof(t_map));
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

//	HACK: DB
	// ft_printf("x = %d\n", map.width);
	// ft_printf("y = %d\n", map.height);
	// ft_printf("%s", line);
	// ft_printf("x = %d\n", map.width);
	// ft_printf("limit = %d\n", map.width / 2);
	// ft_printf("y = %d\n", map.height);
	// DB below for set_point
	// ft_printf("xline + 1 = %s\n", ft_strchr(xline[xi], ',') + 3);
	// ft_printf("deu free\n");
	// ft_printf("buffer = %s", buffer);
	// ft_printf("xi = %d\n", xi);
	// ft_printf("x = %d\n", x);
	// ft_printf("i = %d\n", i);
	// ft_printf("xline = %s\n", xline[xi]);
	// ft_printf("xline + 1 = %s\n", xline[xi + 1]);
	// ft_printf("xttl = %d\n", data->map->width);
		// int	j = 0; //db for split
		// while (xline[j])
		// {
		// 	if (!xline[j + 1])
		// 		ft_printf("\"%s\" \n ", xline[j]);
		// 	else if (xline[j])
		// 		ft_printf("\"%s\" ", xline[j]);
		// 	j++;
		// }
