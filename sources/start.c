/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:51:25 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/27 16:42:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static t_wolf3d		*ft_init_wolf3d(void)
{
	t_wolf3d	*w3d;

	w3d = (t_wolf3d *)ft_memalloc(sizeof(t_wolf3d));
	w3d->mlx = ft_mlx_init(W_WIDTH, W_HEIGHT, "wolf3d");
	w3d->key = -1;
	w3d->player.pos = ft_make_pt(7, 5);
	w3d->player.dir = 90;
	w3d->d.dt = 1;
	w3d->d.elipsedTime = 0;
	get_map1(&w3d->map);
	return (w3d);
}

void				ft_start(void)
{
	t_wolf3d	*w3d;

//	w3d = ft_init_wolf3d();

//	mlx_hook(w3d->mlx->p_win, KeyPress, KeyPressMask, press_wolf3d, w3d);
//	mlx_hook(w3d->mlx->p_win, KeyRelease, KeyPressMask, unpress_wolf3d, w3d);
//	mlx_loop_hook(w3d->mlx->p_mlx, loop_wolf3d, w3d);
//	mlx_loop(w3d->mlx->p_mlx);i

	w3d = (t_wolf3d *)ft_memalloc(sizeof(t_wolf3d));
	w3d->key = -1;
	w3d->player.pos = ft_make_pt(8, 5);
	w3d->player.dir = 0;
	w3d->d.dt = 1;
	w3d->d.elipsedTime = 0;
	get_map1(&w3d->map);

	t_wall	w;
	float deg = 0;

	while (deg < 360)
		w = ft_dist(w3d->map, w3d->player.pos, deg++);

}
