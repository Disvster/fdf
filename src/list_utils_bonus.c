/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:58:35 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/14 20:16:22 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf_bonus.h"
#include "../incs/fdf.h"

t_dlist	*dlist_new_node(void *content)
{
	t_dlist	*new_node;
	
	new_node = malloc(sizeof(t_dlist));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->data = content;
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

void	fdf_dlist_clear(t_dlist **lst, void (*del)(t_data *))
{
	t_dlist	*tmp;
	t_dlist	*node;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		tmp = node->next;
		del(node->data);
		free(node);
		node = tmp;
	}
	*lst = NULL;
	exit(0);
}

t_dlist	*dlist_get_tail(t_dlist *n)
{
    if (!n)
		return (NULL);
    while (n->next)
        n = n->next;
    return (n);
}

t_dlist	*dlist_get_head(t_dlist *n)
{
    if (!n)
		return (NULL);
    while (n->prev)
        n = n->prev;
    return (n);
}

void	bonus_close_window(t_data *data)
{
	free_function(NULL, data);
	if (data && data->mlx)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		if (data && data->mlx)
		{
			free(data->mlx);
			data->mlx = NULL;
		}
	}
}
