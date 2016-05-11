/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:51:25 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/11 11:35:49 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void			ft_init_rc(t_wolf3d *w3d)
{
	w3d->r.pos = w3d->start_pos;
	w3d->r.dir = ft_make_ptd(-1, 0);
	w3d->r.plane = ft_make_ptd(0, 0.66);
}

/*
** void ft_init_rc(); is not a static beacause
** she's called in ft_edit_wolf3d in edit_wolf.c
*/

static void		ft_open_fd(t_wolf3d *w3d, char *path)
{
	int		fd;

	if (!path)
	{
		ft_putstr("Default_map : SELECTED\n");
		w3d->default_map = true;
		w3d->mlx = ft_mlx_init(W_WIDTH, W_HEIGHT, "wolf3d");
		return ;
	}
	ft_putstr("Opening file...\n");
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_putstr("\n\033[31mERROR:\033[0m\nBad path\n");
		ft_exit_wolf3d(w3d, 1);
	}
	ft_putstr(path);
	ft_putstr(" : SELECTED\nStart check map...\n");
	w3d->default_map = false;
	get_map_path(w3d, fd, 0, NULL);
	ft_putstr("All checks are good\n\n");
	w3d->mlx = ft_mlx_init(W_WIDTH, W_HEIGHT, "wolf3d");
}

static void		ft_init_wolf3d(t_wolf3d *w3d)
{
	ft_putstr("Initialising wolf3d\n");
	w3d->key1 = -1;
	w3d->key2 = -1;
	w3d->key3 = -1;
	w3d->key_sprint = 1;
	w3d->key_squat = 1;
	w3d->diff_x = 1;
	w3d->fps_mode = 0;
	w3d->d.dt = 1;
	w3d->d.elipsed_time = 0;
	if (w3d->default_map == true)
	{
		w3d->start_pos = ft_make_ptd(3, 2);
		get_map1(w3d);
	}
	ft_init_rc(w3d);
	w3d->var.data = w3d->mlx->mlx_img->data;
	w3d->var.width = w3d->mlx->mlx_img->width;
	w3d->var.octet = w3d->mlx->mlx_img->octet;
	w3d->var.max_size = w3d->mlx->mlx_img->max_size;
	w3d->var.r = &w3d->r;
	w3d->var.t = &w3d->t;
	w3d->var.key_squat = &w3d->key_squat;
	w3d->var.mlx_height = w3d->mlx->height;
}

void			ft_start(char *path)
{
	t_wolf3d	*w3d;

	ft_putstr("\033[32m--- START ---\033[0m\n");
	w3d = (t_wolf3d *)ft_memalloc(sizeof(t_wolf3d));
	ft_open_fd(w3d, path);
	ft_init_wolf3d(w3d);
	ft_load_textures(w3d, w3d->mlx, &w3d->t);
	ft_putstr("Press M for see MAP\n");
	ft_putstr("Press F for see FPS\n");
	mlx_hook(w3d->mlx->p_win, KeyPress, KeyPressMask, press_wolf3d, w3d);
	mlx_hook(w3d->mlx->p_win, KeyRelease, KeyPressMask, unpress_wolf3d, w3d);
	mlx_hook(w3d->mlx->p_win, MotionNotify, KeyPressMask, mouse_wolf3d, w3d);
	mlx_loop_hook(w3d->mlx->p_mlx, loop_wolf3d, w3d);
	mlx_loop(w3d->mlx->p_mlx);
}
