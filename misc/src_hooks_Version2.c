/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_hooks_Version2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:07:25 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/14 20:13:04 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf_bonus.h"

/*
 * NOTE (integration guidance)
 * - This patch keeps your original key handling for q/e/h/j/k/l/ESC and adds
 *   arrow-key switching helpers.
 * - Because I can't be 100% sure of the exact names/types you used for the
 *   doubly-linked list and the fields that hold mlx/Win/image/current node, the
 *   switching functions below are written as clear, commented stubs you can
 *   drop into your code and adapt quickly to your concrete types.
 *
 * Integration steps (brief):
 * 1) Replace `t_dlist` with the actual type of your list node.
 * 2) Replace uses of node->data, data->current_node, data->img, etc. with
 *    your real field names. I marked all places to adapt with "ADAPT".
 * 3) If your list is already circular, you can remove the wrap helpers.
 * 4) Register the existing key handlers as you already do in main.
 *
 * See below for the actual hook changes (key_press now detects Left/Right).
 */

/* ----- BEGIN: helpers to switch maps (ADAPT THE TYPES/FIELDS) ----- */

/*
 * Example node type name used here: t_dlist
 * Replace t_dlist with your node type (the struct that has next/prev and
 * a pointer to s_data).
 *
 * Expected node layout (conceptual):
 * typedef struct s_map_node
 * {
 *     struct s_map_node *next;
 *     struct s_map_node *prev;
 *     t_data            *data; // pointer to your s_data for that map
 * } t_dlist;
 *
 * If your project already has functions to get head/tail or to show a node,
 * prefer using them and remove the helpers below.
 */

/* find head (first) from any node; remove if your list is circular */
static t_dlist *fdf_get_head(t_dlist *node)
{
    if (!node)
        return (NULL);
    while (node->prev)
        node = node->prev;
    return (node);
}

/* find tail (last) from any node; remove if your list is circular */
static t_dlist *fdf_get_tail(t_dlist *node)
{
    if (!node)
        return (NULL);
    while (node->next)
        node = node->next;
    return (node);
}

/*
 * Replace usages tagged "ADAPT" below with the real field names you used in
 * your project. This function's responsibility is:
 * - update the active context to use the chosen node's map/image
 * - actually put the pre-rendered image to the window
 *
 * Two common patterns in fdf projects:
 *  - the global/context t_data *data holds the mlx and window pointers and
 *    a pointer to the "current node". In that case update data->current_node.
 *  - each node->data is itself the "active" t_data (less common). Adjust
 *    accordingly.
 */
static void fdf_show_node_map(t_data *data, t_dlist *node)
{
    if (!data || !node || !node->data)
        return;

    /* ADAPT: if your t_data stores the current node pointer, set it:
     * data->current_node = node;
     *
     * ADAPT: if your rendering uses a separate image pointer in data, set it:
     * data->img = node->data->img;
     *
     * The two lines below assume:
     * - data->mlx and data->win are the MLX instance/window in your context
     * - node->data->img is the pre-rendered mlx image for that map
     */
    mlx_put_image_to_window(node->data.mlx, data->win, node->data->img, 0, 0);
}

/* move to next; wrap to head if at tail */
static void fdf_next_map(t_data *data)
{
    t_dlist *cur;

    if (!data)
        return;

    /* ADAPT: how you access the current node from your t_data.
     * Examples you may have used:
     *  - data->current_node
     *  - data->node (or a global variable)
     *
     * Replace `data->current_node` below with your actual field.
     */
    cur = data->current_node; /* ADAPT this field name */

    if (!cur)
        return;
    if (cur->next)
        cur = cur->next;
    else
        cur = fdf_get_head(cur); /* wrap if necessary */
    /* update current node in your data/context */
    data->current_node = cur; /* ADAPT if your field name differs */
    fdf_show_node_map(data, cur);
}

/* move to prev; wrap to tail if at head */
static void fdf_prev_map(t_data *data)
{
    t_dlist *cur;

    if (!data)
        return;
    cur = data->current_node; /* ADAPT this field name */
    if (!cur)
        return;
    if (cur->prev)
        cur = cur->prev;
    else
        cur = fdf_get_tail(cur); /* wrap if necessary */
    data->current_node = cur; /* ADAPT if your field name differs */
    fdf_show_node_map(data, cur);
}

/* ----- END: helpers to switch maps ----- */

/* existing key handlers (kept mostly as-is) */

int key_press(int keycode, t_data *data)
{
    if (keycode == 65307)
        fdf_close_window(data);

    /* arrow keys: add right/left to switch maps
     *
     * X11 keysyms:
     *   Left  = XK_Left
     *   Right = XK_Right
     *
     * If you prefer numeric keycodes, Right = 65363, Left = 65361.
     */
    if (keycode == XK_Right || keycode == 65363)
        fdf_next_map(data);
    if (keycode == XK_Left || keycode == 65361)
        fdf_prev_map(data);

    if (keycode == XK_q)
        data->keys.q = true;
    if (keycode == XK_e)
        data->keys.e = true;
    if (keycode == XK_h)
        data->keys.h = true;
    if (keycode == XK_j)
        data->keys.j = true;
    if (keycode == XK_k)
        data->keys.k = true;
    if (keycode == XK_l)
        data->keys.l = true;
    return (0);
}

int key_release(int keycode, t_data *data)
{
    if (keycode == XK_q)
        data->keys.q = false;
    if (keycode == XK_e)
        data->keys.e = false;
    if (keycode == XK_h)
        data->keys.h = false;
    if (keycode == XK_j)
        data->keys.j = false;
    if (keycode == XK_k)
        data->keys.k = false;
    if (keycode == XK_l)
        data->keys.l = false;
    return (0);
}

void handle_changes(t_data *data)
{
    if (data->keys.q)
        data->view.z_scale -= 0.5;
    if (data->keys.e)
        data->view.z_scale += 0.5;
    handle_boundaries(data);
}

void handle_boundaries(t_data *data)
{
    if (data->keys.h)
    {
        data->view.off_x -= 20;
        if (data->view.off_x < -(data->map.width))
            data->view.off_x = IMG_WIDTH;
    }
    if (data->keys.l)
    {
        data->view.off_x += 20;
        if (data->view.off_x > (IMG_WIDTH + data->map.width * 2))
            data->view.off_x = 0;
    }
    if (data->keys.j)
    {
        data->view.off_y += 20;
        if (data->view.off_y > (IMG_HEIGHT + data->map.height * 2))
            data->view.off_y = 0;
    }
    if (data->keys.k)
    {
        data->view.off_y -= 20;
        if (data->view.off_y < -(data->map.height))
            data->view.off_y = IMG_HEIGHT;
    }
}
