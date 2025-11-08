/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:50:28 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/13 23:30:58 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int	main(void)
{
	char	*str = ft_strdup("arara");

	if (!str)
		return (1);
	t_list	*node = ft_lstnew(str);
	if (!node)
	{
		free(str);
		return (1);
	}
	printf("content: %s\n", (char *)node->content);

	free(node->content);
	free(node);
	return (0);
}*/
