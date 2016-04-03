/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::      ::::::::   */
/*   edit_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 16:32:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/03 12:45:46 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

extern int worldMap[24][24];

void	ft_edit_wolf3d(t_wolf3d *w3d)
{
	double		moveSpeed;
	double		rotSpeed;
	t_ptd		*pos;
	t_ptd		*dir;
	double		oldDirX;
	double		oldPlaneX;

	moveSpeed = w3d->d.dt * 5;
	rotSpeed = w3d->d.dt * 3;
	pos = &w3d->r.pos;
	dir = &w3d->r.dir;
	if (w3d->key1 == 49 || w3d->key2 == 49 || w3d->key3 == 49)
		ft_init_rc(&w3d->r);
	if (w3d->key1 == 13 || w3d->key2 == 13 || w3d->key3  == 13)
	{
		if (worldMap[(int)(pos->x + dir->x * moveSpeed)][(int)pos->y]== 0)
			pos->x += w3d->r.dir.x * moveSpeed;
		if (worldMap[(int)(pos->x)][(int)(pos->y + dir->y * moveSpeed)] == 0)
			pos->y += dir->y * moveSpeed;
	}
	else if (w3d->key1 == 1 || w3d->key2 == 1 || w3d->key3 == 1)
	{
		if (worldMap[(int)(pos->x - dir->x * moveSpeed)][(int)pos->y] == 0)
			pos->x -= dir->x * moveSpeed;
		if (worldMap[(int)pos->x][(int)(pos->y - dir->y * moveSpeed)] == 0)
			pos->y -= dir->y * moveSpeed;
	}
	if (w3d->key1 == 0 || w3d->key2 == 0 || w3d->key3 == 0)
	{
		if (worldMap[(int)(pos->x - dir->y * moveSpeed)][(int)(pos->y)] == 0)
			pos->x -= dir->y * moveSpeed;
		if (worldMap[(int)(pos->x)][(int)(pos->y + dir->x * moveSpeed)] == 0)
			pos->y += dir->x * moveSpeed;
	}
	if (w3d->key1 == 2 || w3d->key2 == 2 || w3d->key3 == 2)
	{
		if (worldMap[(int)(pos->x + dir->y * moveSpeed)][(int)(pos->y)] == 0)
			pos->x += dir->y * moveSpeed;
		if (worldMap[(int)(pos->x)][(int)(pos->y - dir->x * moveSpeed)] == 0)
			pos->y -= dir->x * moveSpeed;
	}
	if (w3d->key1 == 124 || w3d->key2 == 124 || w3d->key3 == 124)
	{
		oldDirX = dir->x;
		dir->x = dir->x * cos(-rotSpeed) - dir->y * sin(-rotSpeed);
		dir->y = oldDirX * sin(-rotSpeed) + dir->y * cos(-rotSpeed);
		oldPlaneX = w3d->r.plane.x;
		w3d->r.plane.x = w3d->r.plane.x * cos(-rotSpeed) - w3d->r.plane.y * sin(-rotSpeed);
		w3d->r.plane.y = oldPlaneX * sin(-rotSpeed) + w3d->r.plane.y * cos(-rotSpeed);
	}
	else if (w3d->key1 == 123 || w3d->key2 == 123 || w3d->key3 == 123)
	{
		oldDirX = dir->x;
		dir->x = dir->x * cos(rotSpeed) - dir->y * sin(rotSpeed);
		dir->y = oldDirX * sin(rotSpeed) + dir->y * cos(rotSpeed);
		oldPlaneX = w3d->r.plane.x;
		w3d->r.plane.x = w3d->r.plane.x * cos(rotSpeed) - w3d->r.plane.y * sin(rotSpeed);
		w3d->r.plane.y = oldPlaneX * sin(rotSpeed) + w3d->r.plane.y * cos(rotSpeed);
	}
}
