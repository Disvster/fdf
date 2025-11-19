/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:45:09 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/19 18:07:37 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf_bonus.h"

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
		fdf_init_view(&(data[id]));
		id++;
	}
	return (data);
}

t_dlist	*create_maplist(t_data *data, t_data *window, int n_maps)
{
	t_dlist	*maplist;
	t_dlist	*new_node;
	int		id;

	id = 0;
	maplist = NULL;
	while (id < n_maps)
	{
		new_node = dlist_new_node(&data[id], window);
		if (!new_node)
			return (NULL);
		new_node->window = window;
		if (!maplist)
			maplist = new_node;
		else
			dlist_add_last(&maplist, new_node);
		id++;
	}
	return (maplist);
}

int	new_render_bonus(t_dlist *node)
{
	t_data	*temp;
	t_data	*temp2;

	clear_image(node->data);
	temp = node->data;
	handle_changes_bonus(&node);
	if (temp != node->data)
		clear_image(temp);
	temp2 = node->data;
	transform(temp2);
	render_map(temp2);
	mlx_put_image_to_window(temp2->mlx, temp2->mlx_win, temp2->img, 0, 0);
	return (0);
}

int	hook_exit(t_dlist **node)
{
	fdf_dlist_clear(node, bonus_wipe_image);
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
	init_win_bonus(&window);
	if (!data)
		return (1);
	maplist = create_maplist(data, &window, numb_maps);
	if (!maplist)
		return (1);
	mlx_hook(window.mlx_win, 2, 1L << 0, key_press_bonus, maplist);
	mlx_hook(window.mlx_win, 3, 1L << 1, key_release_bonus, maplist);
	mlx_hook(window.mlx_win, 17, 0, hook_exit, maplist);
	mlx_loop_hook(window.mlx, new_render_bonus, maplist);
	mlx_loop(window.mlx);
	fdf_dlist_clear(&maplist, bonus_wipe_image);
	return (0);
}
