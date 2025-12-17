/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_maps_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:02:01 by manmaria          #+#    #+#             */
/*   Updated: 2025/12/17 18:46:20 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

int	fdf_close_window_bonus(t_data *data)
{
	free_function(NULL, data);
	if (data && data->mlx)
	{
		if (data && data->mlx && data->img)
			mlx_destroy_image(data->mlx, data->img);
		if (data && data->mlx && data->mlx_win)
			mlx_destroy_window(data->mlx, data->mlx_win);
		if (data && data->mlx)
			mlx_destroy_display(data->mlx);
		if (data && data->mlx)
		{
			free(data->mlx);
			data->mlx = NULL;
		}
	}
	return (0);
}

static void	free_function_b(char **buffer, t_data **data)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		if (data)
		{
			*buffer = get_next_line((*data)->fd);
			while (*buffer)
			{
				free(*buffer);
				*buffer = get_next_line((*data)->fd);
			}
		}
		*buffer = NULL;
	}
	if (data && (*data)->points)
	{
		free((*data)->points);
		(*data)->points = NULL;
	}
}

void	bonus_wipe_image(t_data *data)
{
	if (data && data->mlx && data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		free_function_b(NULL, &data);
	}
}

void	init_win_bonus(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(error_exit(-2, "Could not initialize MLX\n"));
	data->mlx_win = mlx_new_window(data->mlx, IMG_WIDTH, IMG_HEIGHT,
			"FdF - manmaria");
	if (!data->mlx_win)
		exit(error_exit(-2, "Could not create MLX Window\n"));
}

void	init_img_bonus(t_data *data)
{
	data->img = mlx_new_image(data->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (!data->img)
		exit(error_exit(-2, "Could not create MLX Image"));
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_length, &data->endian);
	if (!data->addr)
		exit(error_exit(-2, "Could not get MLX Data Address"));
}
