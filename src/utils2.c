/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:15:03 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/13 02:48:37 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

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

int		handle_color_code(char *str, t_data *data)
{
	int	res;
	char *hex;

	res = 0;
	if (str && str + 3)
	{
		hex = ft_strchr(str, 'X');
		if (hex)
			res = ft_atoi_base(&hex[1], "0123456789ABCDEF");
		hex = ft_strchr(str, 'X');
		if (res == 0 && hex)
			res = ft_atoi_base(&hex[1], "0123456789abcdef");
		hex = ft_strchr(str, 'x');
		if (res == 0 && hex)
			res = ft_atoi_base(&hex[1], "0123456789ABCDEF");
		hex = ft_strchr(str, 'x');
		if (res == 0 && hex)
			res = ft_atoi_base(&hex[1], "0123456789abcdef");

	}
	if (res != 0)
		data->map.has_color = true;
	return (res);
}
