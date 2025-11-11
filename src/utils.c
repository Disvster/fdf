/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:20:13 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/08 22:06:34 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	error_exit(int fd, char *str)
{
	if (fd == -1)
		perror("File not found!\n");
	else
	{
		if (str)
			perror(str);
		if (fd > -1)
			close (fd);
	}
	return (1);
}

void	free_function(char **buffer, t_data *data)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (data && data->points)
	{
		free(data->points);
		data->points = NULL;
	}
}

int	fdf_close_window(t_data *data)
{
	free_function(NULL, data);
	if (data && data->mlx)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		if (data && data->mlx)
		{
			free(data->mlx);
			data->mlx = NULL;
		}
		exit(0);
	}
	return (0);
}

void	fdf_init_window(t_data	*data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(error_exit(-2, "Could not initialize MLX\n"));
	data->mlx_win = mlx_new_window(data->mlx, IMG_WIDTH, IMG_HEIGHT,
			"FdF - manmaria");
	if (!data->mlx_win)
		exit(error_exit(-2, "Could not create MLX Window\n"));
	data->img = mlx_new_image(data->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (!data->img)
		exit(error_exit(-2, "Could not create MLX Image"));
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_length, &data->endian);
	if (!data->addr)
		exit(error_exit(-2, "Could not get MLX Data Address"));
}

float	interpl(int n, int start, int end)
{
	return ((float)(n - start) / (float)(end - start));
}
