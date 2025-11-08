/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:46:05 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/08 22:26:14 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
	{
		ft_printf("merdou1\n");// HACK: db
		return ;
	}
	if ( x >= IMG_WIDTH || y >= IMG_HEIGHT)
	{
		ft_printf("merdou2\n");// HACK: db
		return ;
	}
	if (!data || !data->addr)
	{
		ft_printf("merdou3\n");// HACK: db
		return ;
	}
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
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
	if (!data->img)
		exit(error_exit(-2, "Could not get MLX Data Address"));
}

// TODO:
// void	ft_clear_image(t_data *data)
// {
// 	if (!data || !data->addr)
// 		return ;
// 	ft_memset(data->addr, 0, data->w_height * data->line_len);
// }

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	ft_bzero(&data, sizeof(t_data));
	//if ac and av darara ...
	parse_map(&data, av[1]);
	print_map(&data);// HACK: db
	fdf_init_window(&data);
	fdf_init_view(&data);

	transform(&data);
	render_map(&data);

	ft_printf("width = %d, height = %d\n", data.map.width, data.map.height);// HACK: db

	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx);

	free_function(NULL, &data);
}
