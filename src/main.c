/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:46:05 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/22 22:47:31 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;
	t_img	img;

	data = parse_map(av[1]);
	free_points(&data);

	mlx = mlx_init(); //display init
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, 192, 108, "Hello world!"); //window init
	img.img = mlx_new_image(mlx, 192, 108);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 40, 23);
	mlx_loop(mlx);

	free_points(&data);// WARNING:dont forget to free points
}
