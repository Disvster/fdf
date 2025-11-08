/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 22:41:27 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/13 23:34:23 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (!del || !lst)
		return ;
	current = *lst;
	while (current)
	{
		temp = current;
		current = current->next;
		ft_lstdelone(temp, (*del));
	}
	*lst = NULL;
}
/*
int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;
	t_list	d;

	t_list	*ptr;
	a = &b;
	b = &c;
	c = &d;
	d = NULL;

	ft_lstclear(t_list **lst, del);




}*/
