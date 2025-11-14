/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:45:09 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/14 19:41:37 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"
#include "../incs/fdf.h"

int		key_press_bonus(int	keycode, t_dlist *node)
{
	t_data	*data;

	data = node->data;
	if (keycode == XK_Right)
		data->keys.right = true;
	if (keycode == XK_Right)
		data->keys.left = true;
	key_press(keycode, data);
	return (0);
}
int		key_release_bonus(int keycode, t_dlist *node)
{
	t_data	*data;

	data = node->data;
	if (keycode == XK_Right)
		data->keys.right = true;
	if (keycode == XK_Right)
		data->keys.left = true;
	key_release(keycode, data);
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

void	*init_data_array(int ac, char **av)
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

t_dlist	*create_maplist(t_data *data, int n_maps)
{
	t_dlist	*maplist;
	t_dlist	*new_node;
	int		id;

	id = 0;
	maplist = NULL;
	while (id < n_maps)
	{
		new_node = dlist_new_node(&data[id]);
		if (!new_node)
			return (NULL);
		if (!maplist)
			maplist = new_node;
		dlist_add_last(&maplist, new_node);
		id++;
	}
	return (maplist);
}

void	fdf_next_map(t_dlist **node)
{
	t_dlist	*next;

	if (!node)
		return ;
	next = (*node)->next;
	if (!next)
		next = dlist_get_head(*node);
	*node = next;
}

void	fdf_prev_map(t_dlist **node)
{
	t_dlist	*prev;

	if (!node)
		return ;
	prev = (*node)->prev;
	if (!prev)
		prev = dlist_get_tail(*node);
	*node = prev;
}
void	handle_changes_bonus(t_dlist *node)
{
	t_data	*data;

	data = node->data;
	if (data->keys.right)
		fdf_next_map(&node);
	if (data->keys.right)
		fdf_prev_map(&node);
}

int	new_render_bonus(t_dlist *node)
{
	t_data	*temp;

	clear_image(node->data);
	handle_changes(node->data);
	handle_changes_bonus(node);
	temp = node->data;
	transform(temp);
	render_map(temp);
	mlx_put_image_to_window(temp->mlx, temp->mlx_win, temp->img, 0, 0);
	return (0);
}

int	hook_exit(t_dlist *node)
{
	fdf_dlist_clear(&node, &bonus_close_window);
	return (1);
}

int	handle_multiple_maps(int ac, char **av)
{
	int		numb_maps;
	t_data	window;
	t_data	*data;
	t_dlist	*maplist;

	numb_maps = ac - 1;
	ft_bzero(&window, sizeof(t_data));
	data = init_data_array(ac, av);
	if (!data)
		return (1);
	maplist = create_maplist(data, numb_maps);
	if (!maplist)
		return (1);
	fdf_init_window(&window);
	mlx_loop_hook(window.mlx, new_render_bonus, maplist);
	mlx_hook(window.mlx_win, 2, 1L << 0, key_press_bonus, maplist);
	mlx_hook(window.mlx_win, 3, 1L << 1, key_release_bonus, maplist);
	mlx_hook(window.mlx_win, 17, 0, &hook_exit, &maplist);
	mlx_loop(window.mlx);
	fdf_dlist_clear(&maplist, &bonus_close_window);
	return (0);
}
