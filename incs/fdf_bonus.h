/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:47:20 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/14 19:41:44 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "fdf.h"

typedef	struct	s_dlist
{
	struct	s_dlist	*prev;
	void			*data;
	struct	s_dlist	*next;

}				t_dlist;

t_dlist	*dlist_new_node(void *content);
void	dlist_add_first(t_dlist **head, t_dlist *node);
void	dlist_add_last(t_dlist **head, t_dlist *node);
void	fdf_dlist_clear(t_dlist **lst, void (*del)(t_data *));
void	bonusfdf_close_window(t_data *data);

void	*init_data_array(int ac, char **av);

#endif
