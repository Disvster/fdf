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

	if (x < 0 || y < 0 || x >= 1920 || y >= 1080)
		return ;
	if (!data || !data->addr)
		return ;
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
	if (!data->addr)
		exit(error_exit(-2, "Could not get MLX Data Address"));
}

void	draw_background(t_data *data, int color)
{
	unsigned int	i;
	unsigned int	pixel_count;
	int				*dest;

	i = 0;
	pixel_count = IMG_HEIGHT * IMG_WIDTH;
	dest = (int *)data->addr;
	while (i < pixel_count)
		dest[i++] = color;
}

void	clear_image(t_data *data)
{
	int	background_color;

	if (!data || !data->addr)
		return ;
	background_color = 0x000000;
	draw_background(data, background_color);
}

int	new_render(t_data *data)
{
	clear_image(data);
	handle_changes(data);
	transform(data);
	render_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	ft_printf("new_render \n");
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	ft_bzero(&data, sizeof(t_data));
	parse_map(&data, av[1]);
	print_map(&data);// HACK: db
	fdf_init_window(&data);
	fdf_init_view(&data);
	mlx_loop_hook(data.mlx, new_render, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.mlx_win, 17, 0, fdf_close_window, &data);

	ft_printf("width = %d, height = %d\n", data.map.width, data.map.height);// HACK: db
	mlx_loop(data.mlx);

	free_function(NULL, &data);
	return (0);
}
