/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:03:49 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/19 23:09:52 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf_bonus.h"

void	handle_boundaries_bonus(t_data **new, t_data *old);

int	key_press_bonus(int keycode, t_dlist **node)
{
	t_data	*data;

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
	if (keycode == XK_i)
		data->keys.i = true;
	if (keycode == XK_o)
		data->keys.o = true;
	if (keycode == XK_r)
		data->keys.r = true;
	return (0);
}

int	key_release_bonus(int keycode, t_dlist **node)
{
	t_data	*data;

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
	if (keycode == XK_i)
		data->keys.i = false;
	if (keycode == XK_o)
		data->keys.o = false;
	if (keycode == XK_r)
		data->keys.r = false;
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
	t_data	*dtmp1;
	t_data	*dtmp2;
	t_dlist	*temp;

	temp = *node;
	dtmp1 = temp->data;
	if (dtmp1->keys.right)
	{
		fdf_next_map(&temp);
		dtmp1->keys.right = false;
	}
	if (dtmp1->keys.left)
	{
		fdf_prev_map(&temp);
		dtmp1->keys.left = false;
	}
	dtmp2 = temp->data;
	if (dtmp1->keys.q)
		dtmp2->view.z_scale -= 0.5;
	if (dtmp1->keys.e)
		dtmp2->view.z_scale += 0.5;
	if (dtmp1->keys.o)
		dtmp2->view.zoom -= 0.005;
	if (dtmp1->keys.i)
		dtmp2->view.zoom += 0.005;
	if (dtmp1->keys.r)
		fdf_init_view(temp->data);
	handle_boundaries_bonus(&dtmp2, dtmp1);
	*node = temp;
}

void	handle_boundaries_bonus(t_data **new, t_data *old)
{
	if (old->keys.h)
	{
		(*new)->view.off_x -= 20;
		if ((*new)->view.off_x < -((*new)->map.width))
			(*new)->view.off_x = IMG_WIDTH;
	}
	if (old->keys.l)
	{
		(*new)->view.off_x += 20;
		if ((*new)->view.off_x > (IMG_WIDTH + (*new)->map.width * 2))
			(*new)->view.off_x = 0;
	}
	if (old->keys.j)
	{
		(*new)->view.off_y += 20;
		if ((*new)->view.off_y > (IMG_HEIGHT + (*new)->map.height * 2))
			(*new)->view.off_y = 0;
	}
	if (old->keys.k)
	{
		(*new)->view.off_y -= 20;
		if ((*new)->view.off_y < -((*new)->map.height))
			(*new)->view.off_y = IMG_HEIGHT;
	}
}
