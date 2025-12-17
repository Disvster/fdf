/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:46:05 by manmaria          #+#    #+#             */
/*   Updated: 2025/12/17 18:46:32 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

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
	if (!data || !data->addr)
		return ;
	draw_background(data, BG_COLOR);
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

	if (check_valid_files(ac, av) == 0)
		return (1);
	ft_bzero(&data, sizeof(t_data));
	if (ac > 2)
		return (handle_multiple_maps(ac, av));
	else
	{
		parse_map(&data, av[1]);
		fdf_init_window(&data);
		fdf_init_view(&data);
		mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
		mlx_hook(data.mlx_win, 3, 1L << 1, key_release, &data);
		mlx_hook(data.mlx_win, 17, 0, fdf_close_window, &data);
		mlx_loop_hook(data.mlx, new_render, &data);
		mlx_loop(data.mlx);
		free_function(NULL, &data);
	}
	return (0);
}
