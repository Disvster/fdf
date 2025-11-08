/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:50:40 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/17 19:27:01 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_node_content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_node_content = f(lst->content);
		new_node = ft_lstnew(new_node_content);
		if (!new_node)
		{
			del(new_node_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
#include <stdio.h>

void	*ft_dup_content(void *content)
{
	return (ft_strdup((char *)content));
}

void	ft_del_content(void *content)
{
	free(content);
}

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_list *original = ft_lstnew(ft_strdup("one"));
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("two")));
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("three")));

	ft_print_list(original);

	t_list *mapped = ft_lstmap(original, ft_dup_content, ft_del_content);

	ft_print_list(mapped);

	ft_lstclear(&original, ft_del_content);
	ft_lstclear(&mapped, ft_del_content);

	return 0;
}*/
