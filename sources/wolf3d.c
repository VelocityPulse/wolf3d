/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:45:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/24 16:25:24 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_wolf3d(t_wolf3d *w3d)
{
	float	deg;
	float	div;
	int		x;

	div = 60 / W_WIDTH;
	x = -1;
	deg = w3d->player.dir - 30;
	while (++x < W_WIDTH)
	{
		ft_trace(ft_dist(w3d->map, w3d->player, deg));
		deg += div;
	}
	ft_flush_image(w3d->mlx);
}
