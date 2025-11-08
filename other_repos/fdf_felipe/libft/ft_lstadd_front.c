/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 01:03:44 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/13 04:15:28 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
int	main(void)
{
	char	*inteiro;
	t_list a;
	t_list b;
	t_list c;
	t_list d;
	t_list *current;

	d.content = (char *)"arara";



	a.content = (char *)"felipe";
	a.next = &b;


	a.next->content = (char *)"maria";
	a.next->next = &c;


	a.next->next->content = (char *)"joao";
	a.next->next->next = NULL;

	current = &a;
	while (current)
	{
		inteiro = (char *)(current->content);
		printf("%s\n", inteiro);
		current = current->next;
	}
	printf("\n\n");
	current = &a;
	ft_lstadd_front(&current, &d);
	while (current)
	{
		inteiro = (char *)(current->content);
		printf("%s\n", inteiro);
		current = current->next;
	}
	return (0);
}*/
