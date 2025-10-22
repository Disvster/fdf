/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:43:35 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/22 00:26:20 by manmaria         ###   ########.fr       */
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
	if (!line)
		exit (1);// HACK:
	map.width = count_words_fdf(line, " \n");
	while (line)
	{
		map.height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map.points_total = map.width * map.height;
	return (map);
}
	// ft_printf("%s", line);// HACK: db
	// ft_printf("x = %d\n", map.width);// HACK: db
	// ft_printf("limit = %d\n", map.width / 2);// HACK: db
	// ft_printf("y = %d\n", map.height);// HACK: db

void	*map_read_data(t_data *data, int fd)// FIX: size
{
	int		x;
	int		y;
	int		i;
	char	*buffer;

	if (!data)
		return (NULL/*free_func(data)*/);// TODO: free data 
	i = 0;
	x = -1 * (data->map->width / 2);
	y = -1 * (data->map->height / 2);
	buffer = NULL;
	while ((y + (data->map->height % 2 != 0)) <= (data->map->height / 2))
	{
		buffer = get_next_line(fd);
		if (!buffer)
			return (free_buffer(buffer)/*and data */); //TODO: free data
		while ((x + (data->map->width % 2 != 0)) < (data->map->width / 2))
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
		exit (1);
	}
	map_data = map_data_init(map_fd);
	close(map_fd);
	points = ft_calloc(sizeof(t_point), map_data.points_total);
	if (!points)
		return (write(2, "ERROR @ parse_map\n", 18), exit (1));// HACK: db
	map_fd = open(file_name, O_RDONLY);
	data.map = &map_data;
	data.points = points;
	map_read_data(&data, map_fd);
	print_map(&data);
	close(map_fd);
	free_points(&data);// WARNING:dont forget to free points
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
