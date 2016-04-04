/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 14:55:44 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/04 15:20:15 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

extern int		worldMap[24][24];

static void		edit_backfront(t_wolf3d *w3d, t_ptd *pos, t_ptd *dir)
{
	double		move_speed;

	move_speed = w3d->d.dt * 5;
	if (w3d->key1 == 13 || w3d->key2 == 13 || w3d->key3 == 13)
	{
		if (worldMap[(int)(pos->x + dir->x * move_speed)][(int)pos->y] == 0)
			pos->x += w3d->r.dir.x * move_speed;
		if (worldMap[(int)(pos->x)][(int)(pos->y + dir->y * move_speed)] == 0)
			pos->y += dir->y * move_speed;
	}
	else if (w3d->key1 == 1 || w3d->key2 == 1 || w3d->key3 == 1)
	{
		if (worldMap[(int)(pos->x - dir->x * move_speed)][(int)pos->y] == 0)
			pos->x -= dir->x * move_speed;
		if (worldMap[(int)pos->x][(int)(pos->y - dir->y * move_speed)] == 0)
			pos->y -= dir->y * move_speed;
	}
}

static void		edit_lateral(t_wolf3d *w3d, t_ptd *pos, t_ptd *dir)
{
	double		move_speed;

	move_speed = w3d->d.dt * 5;
	if (w3d->key1 == 0 || w3d->key2 == 0 || w3d->key3 == 0)
	{
		if (worldMap[(int)(pos->x - dir->y * move_speed)][(int)(pos->y)] == 0)
			pos->x -= dir->y * move_speed;
		if (worldMap[(int)(pos->x)][(int)(pos->y + dir->x * move_speed)] == 0)
			pos->y += dir->x * move_speed;
	}
	if (w3d->key1 == 2 || w3d->key2 == 2 || w3d->key3 == 2)
	{
		if (worldMap[(int)(pos->x + dir->y * move_speed)][(int)(pos->y)] == 0)
			pos->x += dir->y * move_speed;
		if (worldMap[(int)(pos->x)][(int)(pos->y - dir->x * move_speed)] == 0)
			pos->y -= dir->x * move_speed;
	}
}

void		edit_direction(t_wolf3d *w3d, t_ptd *pos, t_ptd *dir, t_ptd *p)
{
	double		rot_speed;
	double		old_dirx;
	double		old_planex;

	rot_speed = w3d->d.dt * 3 * w3d->diff_x;
	if (w3d->key1 == 124 || w3d->key2 == 124 || w3d->key3 == 124)
	{
		old_dirx = dir->x;
		dir->x = dir->x * cos(-rot_speed) - dir->y * sin(-rot_speed);
		dir->y = old_dirx * sin(-rot_speed) + dir->y * cos(-rot_speed);
		old_planex = p->x;
		p->x = p->x * cos(-rot_speed) - p->y * sin(-rot_speed);
		p->y = old_planex * sin(-rot_speed) + p->y * cos(-rot_speed);
	}
	else if (w3d->key1 == 123 || w3d->key2 == 123 || w3d->key3 == 123)
	{
		old_dirx = dir->x;
		dir->x = dir->x * cos(rot_speed) - dir->y * sin(rot_speed);
		dir->y = old_dirx * sin(rot_speed) + dir->y * cos(rot_speed);
		old_planex = p->x;
		p->x = p->x * cos(rot_speed) - p->y * sin(rot_speed);
		p->y = old_planex * sin(rot_speed) + p->y * cos(rot_speed);
	}
}

/*
 **
 ** void edit_direction(); is not a static because
 ** she called in mouse_wolf3d in wolf_hook.c
 **
*/

void			ft_edit_wolf3d(t_wolf3d *w3d)
{
	if (w3d->key1 == 49 || w3d->key2 == 49 || w3d->key3 == 49)
		ft_init_rc(&w3d->r);
	edit_backfront(w3d, &w3d->r.pos, &w3d->r.dir);
	edit_lateral(w3d, &w3d->r.pos, &w3d->r.dir);
	edit_direction(w3d, &w3d->r.pos, &w3d->r.dir, &w3d->r.plane);
}
