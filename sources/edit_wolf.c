/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 16:32:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/30 17:25:24 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_edit_wolf3d(t_wolf3d *w3d)
{
	double		moveSpeed;
	double		rotSpeed;
	t_pt		pos;
	double		oldDirX;
	double		oldPlaneX;


	moveSpeed = w3d->d.dt * 5;
	rotSpeed = w3d->d.dt * 3;
	pos = ft_make_pt(w3d->r.posX, w3d->r.posY);
	if (w3d->key == 126)
	{
		if (w3d->map.map[(int)(((pos.y - 1) * w3d->map.size.x) + ((pos.y + w3d->r.dirX * moveSpeed) - 1))] == 0)
			w3d->r.posX += w3d->r.dirX * moveSpeed;
		if (w3d->map.map[(int)(((pos.y + w3d->r.dirY * moveSpeed) - 1) + (pos.x - 1))] == 0)
			w3d->r.posY += w3d->r.dirY * moveSpeed;
	}
	else if (w3d->key == 125)
	{
		if (w3d->map.map[(int)(((pos.y - 1) * w3d->map.size.x) + ((pos.y - w3d->r.dirX * moveSpeed) - 1))] == 0)
			w3d->r.posX -= w3d->r.dirX * moveSpeed;
		if (w3d->map.map[(int)(((pos.y - w3d->r.dirY * moveSpeed) - 1) + (pos.x - 1))] == 0)
			w3d->r.posY -= w3d->r.dirY * moveSpeed;
	}
	else if (w3d->key == 124)
	{
		oldDirX = w3d->r.dirX;
		w3d->r.dirX = w3d->r.dirX * cos(-rotSpeed) - w3d->r.dirY * sin(-rotSpeed);
		w3d->r.dirY = oldDirX * sin(-rotSpeed) + w3d->r.dirY * cos(rotSpeed);
		oldPlaneX = w3d->r.planeX;
		w3d->r.planeX = w3d->r.planeX * cos(-rotSpeed) - w3d->r.planeY * sin(-rotSpeed);
		w3d->r.planeY = oldPlaneX * sin(-rotSpeed) + w3d->r.planeY * cos(-rotSpeed);
	}
	else if (w3d->key == 123)
	{
		oldDirX = w3d->r.dirX;
		w3d->r.dirX = w3d->r.dirX * cos(rotSpeed) - w3d->r.dirY * sin(rotSpeed);
		w3d->r.dirY = oldDirX * sin(rotSpeed) + w3d->r.dirY * cos(rotSpeed);
		oldPlaneX = w3d->r.planeX;
		w3d->r.planeX = w3d->r.planeX * cos(rotSpeed) - w3d->r.planeY * sin(rotSpeed);
		w3d->r.planeY = oldPlaneX * sin(rotSpeed) + w3d->r.planeY * cos(rotSpeed);
	}
}
