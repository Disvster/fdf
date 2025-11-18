/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:47:20 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/15 18:24:08 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "fdf.h"

typedef	struct	s_dlist
{
	struct	s_dlist	*prev;
	void			*data;
	t_data			*window;
	struct	s_dlist	*next;

}				t_dlist;

t_dlist	*dlist_new_node(void *content, t_data *window);
t_dlist	*dlist_get_head(t_dlist *n);
t_dlist	*dlist_get_tail(t_dlist *n);
void	dlist_add_first(t_dlist **head, t_dlist *node);
void	dlist_add_last(t_dlist **head, t_dlist *node);
void	fdf_dlist_clear(t_dlist **lst, void (*del)(t_data *));
void	bonus_wipe_image(t_data *data);
int		fdf_close_window_bonus(t_data *data);

void	handle_changes_bonus(t_dlist **node);
int		key_press_bonus(int	keycode, t_dlist *node);
int		key_release_bonus(int keycode, t_dlist *node);

void	*init_data_array(int ac, char **av);
void	init_img_bonus(t_data *data);
void	init_win_bonus(t_data *data);

t_dlist	*create_maplist(t_data *data, t_data *window, int n_maps);
int		new_render_bonus(t_dlist *node);

#endif
