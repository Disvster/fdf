/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:29:12 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/13 23:02:10 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
/*
void	delnode(t_list node)
{
	free(node);
}

int	main(void)
{
	t_list	a = malloc(sizeof(t_list));
	t_list	*ptr;
	
	ptr = &a;
	ft_lstdelone(ptr, delnode);
	return (0);
}*/
