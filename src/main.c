/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:46:05 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/11 19:06:33 by manmaria         ###   ########.fr       */
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
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	// (void)ac;
	ft_bzero(&data, sizeof(t_data));
	parse_map(&data, av[1]);
	fdf_init_window(&data);
	fdf_init_view(&data);
	mlx_loop_hook(data.mlx, new_render, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.mlx_win, 17, 0, fdf_close_window, &data);
	mlx_loop(data.mlx);
	free_function(NULL, &data);
	return (0);
}
