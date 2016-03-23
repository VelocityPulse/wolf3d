/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:51:25 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/21 16:44:29 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static t_wolf3d		*ft_init_wolf3d(void)
{
	t_wolf3d	*w3d;

	w3d = (t_wolf3d *)ft_memalloc(sizeof(t_wolf3d));
	w3d->mlx = ft_mlx_init(W_WIDTH, W_HEIGHT, "wolf3d");
	w3d->key = -1;
	w3d->player.pos = ft_make_pt(10, 10);
	w3d->player.dir = 90;
	return (w3d);
}

void				ft_start(void)
{
	t_wolf3d	*w3d;

	w3d = ft_init_wolf3d();

	mlx_hook(w3d->mlx->p_win, KeyPress, KeyPressMask, press_wolf3d, w3d);
	mlx_hook(w3d->mlx->p_win, KeyRelease, KeyPressMask, unpress_wolf3d, w3d);
	mlx_loop_hook(w3d->mlx->p_mlx, loop_wolf3d, w3d);
	mlx_loop(w3d->mlx->p_mlx);
}