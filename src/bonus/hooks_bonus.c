/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:03:49 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/19 23:04:40 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf_bonus.h"

int	key_press_bonus(int keycode, t_dlist **node)
{
	// t_data	*data;
	//
	// data = (*node)->data;
	// if (keycode == 65307)
	// 	fdf_dlist_clear(node, bonus_wipe_image);
	// if (keycode == XK_Right)
	// 	data->keys.right = true;
	// if (keycode == XK_Left)
	// 	data->keys.left = true;
	// if (keycode == XK_q)
	// 	data->keys.q = true;
	// if (keycode == XK_e)
	// 	data->keys.e = true;
	// if (keycode == XK_h)
	// 	data->keys.h = true;
	// if (keycode == XK_j)
	// 	data->keys.j = true;
	// if (keycode == XK_k)
	// 	data->keys.k = true;
	// if (keycode == XK_l)
	// 	data->keys.l = true;
	// return (0);
	t_data	*data;

	if (!node || !*node)
		return (0);
	/* use shared window state to avoid per-node races when switching maps */
	data = (*node)->window;
	if (!data)
		data = (*node)->data;
	if (keycode == 65307)
		fdf_dlist_clear(node, bonus_wipe_image);
	if (keycode == XK_Right)
		data->keys.right = true;
	if (keycode == XK_Left)
		data->keys.left = true;
	if (keycode == XK_q)
		data->keys.q = true;
	if (keycode == XK_e)
		data->keys.e = true;
	if (keycode == XK_h)
		data->keys.h = true;
	if (keycode == XK_j)
		data->keys.j = true;
	if (keycode == XK_k)
		data->keys.k = true;
	if (keycode == XK_l)
		data->keys.l = true;
	return (0);
}

int	key_release_bonus(int keycode, t_dlist **node)
{
	// t_data	*data;
	//
	// data = (*node)->data;
	// if (keycode == XK_Right)
	// 	data->keys.right = false;
	// if (keycode == XK_Left)
	// 	data->keys.left = false;
	// if (keycode == XK_q)
	// 	data->keys.q = false;
	// if (keycode == XK_e)
	// 	data->keys.e = false;
	// if (keycode == XK_h)
	// 	data->keys.h = false;
	// if (keycode == XK_j)
	// 	data->keys.j = false;
	// if (keycode == XK_k)
	// 	data->keys.k = false;
	// if (keycode == XK_l)
	// 	data->keys.l = false;
	// return (0);
	t_data	*data;

	if (!node || !*node)
		return (0);
	/* mirror press logic: update the shared window state */
	data = (*node)->window;
	if (!data)
		data = (*node)->data;
	if (keycode == XK_Right)
		data->keys.right = false;
	if (keycode == XK_Left)
		data->keys.left = false;
	if (keycode == XK_q)
		data->keys.q = false;
	if (keycode == XK_e)
		data->keys.e = false;
	if (keycode == XK_h)
		data->keys.h = false;
	if (keycode == XK_j)
		data->keys.j = false;
	if (keycode == XK_k)
		data->keys.k = false;
	if (keycode == XK_l)
		data->keys.l = false;
	return (0);
}

void	fdf_next_map(t_dlist **node)
{
	t_dlist	*next;

	if (!*node)
		return ;
	next = (*node)->next;
	if (!next)
		next = dlist_get_head(*node);
	*node = next;
}

void	fdf_prev_map(t_dlist **node)
{
	t_dlist	*prev;

	if (!*node)
		return ;
	prev = (*node)->prev;
	if (!prev)
		prev = dlist_get_tail(*node);
	*node = prev;
}

void	handle_changes_bonus(t_dlist **node)
{
	// t_data	*dtmp1;
	// t_data	*dtmp2;
	// t_dlist	*temp;
	//
	// temp = *node;
	// dtmp1 = temp->data;
	// if (dtmp1->keys.right)
	// // {
	// // 	clear_image(dtmp1);
	// 	fdf_next_map(&temp);
	// // }
	// if (dtmp1->keys.left)
	// // {
	// // 	clear_image(dtmp1);
	// 	fdf_prev_map(&temp);
	// // }
	// dtmp2 = temp->data;
	// if (dtmp1->keys.q)
	// 	dtmp2->view.z_scale -= 0.5;
	// if (dtmp1->keys.e)
	// 	dtmp2->view.z_scale += 0.5;
	// *node = temp;
	t_data	*dtmp_win; /* keys live in the shared window struct */
	t_data	*dtmp_map;
	t_dlist	*temp;

	if (!node || !*node)
		return ;
	temp = *node;
	/* read keys from the shared window (each node should point to same window) */
	dtmp_win = temp->window;
	if (!dtmp_win)
		dtmp_win = temp->data;
	/* move pointer based on shared key state */
	if (dtmp_win->keys.right)
		fdf_next_map(&temp);
	if (dtmp_win->keys.left)
		fdf_prev_map(&temp);
	/* apply z-scale changes to the (new) active map */
	dtmp_map = temp->data;
	if (dtmp_win->keys.q)
		dtmp_map->view.z_scale -= 0.5;
	if (dtmp_win->keys.e)
		dtmp_map->view.z_scale += 0.5;
	*node = temp;
}
//
// void	handle_boundaries_bonus(t_data *data)
// {
// 	if (data->keys.h)
// 	{
// 		data->view.off_x -= 20;
// 		if (data->view.off_x < -(data->map.width))
// 			data->view.off_x = IMG_WIDTH;
// 	}
// 	if (data->keys.l)
// 	{
// 		data->view.off_x += 20;
// 		if (data->view.off_x > (IMG_WIDTH + data->map.width * 2))
// 			data->view.off_x = 0;
// 	}
// 	if (data->keys.j)
// 	{
// 		data->view.off_y += 20;
// 		if (data->view.off_y > (IMG_HEIGHT + data->map.height * 2))
// 			data->view.off_y = 0;
// 	}
// 	if (data->keys.k)
// 	{
// 		data->view.off_y -= 20;
// 		if (data->view.off_y < -(data->map.height))
// 			data->view.off_y = IMG_HEIGHT;
// 	}
// }
