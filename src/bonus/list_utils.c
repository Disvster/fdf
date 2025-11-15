/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:58:35 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/15 18:24:18 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf_bonus.h"

t_dlist	*dlist_new_node(void *content, t_data *window)
{
	t_dlist	*new_node;
	t_data	*temp;

	new_node = malloc(sizeof(t_dlist));
	if (!new_node)
		return (NULL);
	temp = content;
	temp->mlx = window->mlx;
	temp->mlx_win = window->mlx_win;
	init_img_bonus(temp);
	new_node->prev = NULL;
	new_node->data = temp;
	new_node->next = NULL;
	return (new_node);
}

void	dlist_add_first(t_dlist **head, t_dlist *node)
{
	t_dlist	*first;

	if (!*head)
		*head = node;
	else
	{
		first = dlist_get_head(*head);
		first->prev = node;
		node->next = first;
	}
}

void	dlist_add_last(t_dlist **head, t_dlist *node)
{
	t_dlist	*last;

	if (!*head)
		*head = node;
	else
	{
		last = dlist_get_tail(*head);
		last->next = node;
		node->prev = last;
	}
}

//del is bonus_close_window
void	fdf_dlist_clear(t_dlist **lst, void (*del)(t_data *))
{
	t_dlist	*tmp;
	t_dlist	*node;

	if (!lst || !del)
		return ;
	node = *lst;
	if (node->prev)
		node = dlist_get_head(*lst);
	while (node)
	{
		tmp = node->next;
		if (!tmp)
			fdf_close_window_bonus(node->data);
		else
		{
			del(node->data);
			free(node);
		}
		node = tmp;
	}
	*lst = NULL;
	exit(0);
}
