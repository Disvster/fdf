/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_changes_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:48:12 by manmaria          #+#    #+#             */
/*   Updated: 2025/12/17 18:46:32 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"

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
	t_data	*oldmap;
	t_data	*newmap;
	t_dlist	*temp;

	temp = *node;
	oldmap = temp->data;
	if (oldmap->keys.right)
	{
		fdf_next_map(&temp);
		oldmap->keys.right = false;
	}
	if (oldmap->keys.left)
	{
		fdf_prev_map(&temp);
		oldmap->keys.left = false;
	}
	newmap = temp->data;
	handle_scale_and_zoom(&newmap, oldmap);
	if (oldmap->keys.r)
		fdf_init_view(temp->data);
	handle_boundaries_bonus(&newmap, oldmap);
	*node = temp;
}

void	handle_scale_and_zoom(t_data **newmap, t_data *oldmap)
{
	if (oldmap->keys.q)
		(*newmap)->view.z_scale -= 0.5;
	if (oldmap->keys.e)
		(*newmap)->view.z_scale += 0.5;
	if (oldmap->keys.o)
		(*newmap)->view.zoom -= 0.005;
	if (oldmap->keys.i)
		(*newmap)->view.zoom += 0.005;
}

void	handle_boundaries_bonus(t_data **newmap, t_data *oldmap)
{
	if (oldmap->keys.h)
	{
		(*newmap)->view.off_x -= 20;
		if ((*newmap)->view.off_x < -((*newmap)->map.width))
			(*newmap)->view.off_x = IMG_WIDTH;
	}
	if (oldmap->keys.l)
	{
		(*newmap)->view.off_x += 20;
		if ((*newmap)->view.off_x > (IMG_WIDTH + (*newmap)->map.width * 2))
			(*newmap)->view.off_x = 0;
	}
	if (oldmap->keys.j)
	{
		(*newmap)->view.off_y += 20;
		if ((*newmap)->view.off_y > (IMG_HEIGHT + (*newmap)->map.height * 2))
			(*newmap)->view.off_y = 0;
	}
	if (oldmap->keys.k)
	{
		(*newmap)->view.off_y -= 20;
		if ((*newmap)->view.off_y < -((*newmap)->map.height))
			(*newmap)->view.off_y = IMG_HEIGHT;
	}
}
