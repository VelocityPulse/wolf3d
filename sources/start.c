/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:51:25 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/06 11:36:13 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void				ft_init_rc(t_raycasting *r)
{
	r->pos = ft_make_ptd(22, 12);
	r->dir = ft_make_ptd(-1, 0);
	r->plane = ft_make_ptd(0, 0.66);
}

static t_wolf3d		*ft_init_wolf3d(void)
{
	t_wolf3d	*w3d;

	w3d = (t_wolf3d *)ft_memalloc(sizeof(t_wolf3d));
	w3d->mlx = ft_mlx_init(W_WIDTH, W_HEIGHT, "wolf3d");
	w3d->key1 = -1;
	w3d->key2 = -1;
	w3d->key3 = -1;
	w3d->diff_x = 1;
	w3d->fps_mode = 0;
	w3d->d.dt = 1;
	w3d->d.elipsed_time = 0;
	get_map1(&w3d->map);
	ft_init_rc(&w3d->r);
	return (w3d);
}

void				ft_start(void)
{
	t_wolf3d	*w3d;

	w3d = ft_init_wolf3d();

	mlx_hook(w3d->mlx->p_win, KeyPress, KeyPressMask, press_wolf3d, w3d);
//	mlx_hook(w3d->mlx->p_win, KeyRelease, KeyPressMask, unpress_wolf3d, w3d);
//	mlx_hook(w3d->mlx->p_win, MotionNotify, KeyPressMask, mouse_wolf3d, w3d);
	mlx_loop_hook(w3d->mlx->p_mlx, loop_wolf3d, w3d);
	
	mlx_loop(w3d->mlx->p_mlx);
}
