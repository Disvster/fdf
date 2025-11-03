/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:46:05 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/27 00:08:09 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
	{
		ft_printf("merdou1\n");
		return ;
	}
	if ( x >= IMG_WIDTH || y >= IMG_HEIGHT)
	{
		ft_printf("merdou2\n");
		return ;
	}
	if (!img || !img->addr)
	{
		ft_printf("merdou3\n");
		return ;
	}
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;
	t_img	img;

	(void)ac;
	data = parse_map(av[1]);
	
	print_map(&data);// HACK: db

	mlx = mlx_init(); //display init
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, IMG_WIDTH, IMG_HEIGHT, "FdF");
	img.img = mlx_new_image(mlx, IMG_WIDTH, IMG_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	data.img = &img;
	transform(&data);
	render_map(&data);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//destroy img and window
	mlx_loop(mlx);

	free_function(NULL, &data);
}
