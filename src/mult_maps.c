/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:45:09 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/13 23:23:20 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

// TODO: bonus com listas ligadas
//		 em vez de usar um array de data's
//		 usar uma lista de data's com next e previous e circular
//		 para dar cycle dos mapas quando as arrow keys fossem premidas

int		key_press_bonus(int	keycode, t_data *data)
{
	if (keycode == XK_Right)
		data->keys.right = true;
	if (keycode == XK_Right)
		data->keys.left = true;
	return (0);
}

int		key_release_bonus(int	keycode, t_data *data)
{
	if (keycode == XK_Right)
		data->keys.right = true;
	if (keycode == XK_Right)
		data->keys.left = true;
	return (0);
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

void	handle_changes_bonus(t_data *data)
{
	if (data->keys
}

void	*init_array(int ac, char **av)
{
	t_data	*data;
	int		id;

	data = ft_calloc(sizeof(t_data), ac - 1);
	if (!data)
		return (NULL);
	id = 0;
	while (av[id + 1])
	{
		parse_map(&(data[id]), av[id + 1]);
		fdf_init_window(&(data[id]));
		fdf_init_view(&(data[id]));
		init_img_bonus(&(data[id]));
		id++;
	}
	return (data);
}

int	handle_multiple_maps(int ac, char **av)
{
	int		numb_maps;
	t_data	*data;

	numb_maps = ac - 1;
	data = init_array(ac, av);
	if (!data)
		return (1);
	fdf_init_window(&data[0]);
	return (0);
}
