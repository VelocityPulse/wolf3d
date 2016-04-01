/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::      ::::::::   */
/*   edit_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 16:32:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/01 13:11:18 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

extern int worldMap[24][24];

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
	if (w3d->key == 49)
		ft_init_rc(&w3d->r);
	if (w3d->key == 126)
	{
		if (worldMap[(int)(w3d->r.posX + w3d->r.dirX * moveSpeed)][(int)w3d->r.posY]== 0)
			w3d->r.posX += w3d->r.dirX * moveSpeed;
		if (worldMap[pos.x][(int)(w3d->r.posY + w3d->r.dirY * moveSpeed)] == 0)
			w3d->r.posY += w3d->r.dirY * moveSpeed;
	}
	else if (w3d->key == 125)
	{
		if (worldMap[(int)(w3d->r.posX - w3d->r.dirX * moveSpeed)][(int)w3d->r.posY] == 0)
			w3d->r.posX -= w3d->r.dirX * moveSpeed;
		if (worldMap[(int)w3d->r.posX][(int)(w3d->r.posY - w3d->r.dirY * moveSpeed)] == 0)
			w3d->r.posY -= w3d->r.dirY * moveSpeed;
	}
	else if (w3d->key == 124)
	{
		oldDirX = w3d->r.dirX;
		w3d->r.dirX = w3d->r.dirX * cos(-rotSpeed) - w3d->r.dirY * sin(-rotSpeed);
		w3d->r.dirY = oldDirX * sin(-rotSpeed) + w3d->r.dirY * cos(-rotSpeed);
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
