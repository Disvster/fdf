/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:46:05 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/23 21:53:56 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= 1920 || y >= 1080)
	{
		ft_printf("merdou1\n");
		return ;
	}
	if (!img || !img->addr)
	{
		ft_printf("merdou2\n");
		return ;
	}
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_data *data, t_img *img)
{
	int	color;
	int	i;

	color = 0;
	i = -1;
	while (++i < data->map.points_total)
	{
		if (data->points[i].color != 0)
			color = data->points[i].color;
		else
			color = 0x00FF0000;
		my_mlx_pixel_put(img,
				   data->points[i].display[0],
				   data->points[i].display[1],
				   color);
	}
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;
	t_img	img;

	(void)ac;
	data = parse_map(av[1]);

	mlx = mlx_init(); //display init
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, 500, 500, "FdF");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	transform(&data);
	print_img(&data);
	draw_line(&data, &img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//destroy img and window
	mlx_loop(mlx);

	free_points(&data);// WARNING:dont forget to free points
}
