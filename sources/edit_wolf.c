/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:09:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/03 12:09:38 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		edit_backfront(t_wolf3d *w3d, t_ptd *pos, t_ptd *dir)
{
	double		mv_speed;

	mv_speed = ((w3d->d.dt * 5) * w3d->key_squat) * w3d->key_sprint;
	if (w3d->key1 == 13 || w3d->key2 == 13 || w3d->key3 == 13)
	{
		if (w3d->map[(int)(pos->x + dir->x * mv_speed)][(int)pos->y] == 0)
			pos->x += w3d->r.dir.x * mv_speed;
		if (w3d->map[(int)pos->x][(int)(pos->y + dir->y * mv_speed)] == 0)
			pos->y += dir->y * mv_speed;
	}
	else if (w3d->key1 == 1 || w3d->key2 == 1 || w3d->key3 == 1)
	{
		if (w3d->map[(int)(pos->x - dir->x * mv_speed)][(int)pos->y] == 0)
			pos->x -= dir->x * mv_speed;
		if (w3d->map[(int)pos->x][(int)(pos->y - dir->y * mv_speed)] == 0)
			pos->y -= dir->y * mv_speed;
	}
}

static void		edit_lateral(t_wolf3d *w3d, t_ptd *pos, t_ptd *dir)
{
	double		mv_speed;

	mv_speed = (w3d->d.dt * 5) * w3d->key_squat;
	if (w3d->key1 == 0 || w3d->key2 == 0 || w3d->key3 == 0)
	{
		if (w3d->map[(int)(pos->x - dir->y * mv_speed)][(int)pos->y] == 0)
			pos->x -= dir->y * mv_speed;
		if (w3d->map[(int)pos->x][(int)(pos->y + dir->x * mv_speed)] == 0)
			pos->y += dir->x * mv_speed;
	}
	if (w3d->key1 == 2 || w3d->key2 == 2 || w3d->key3 == 2)
	{
		if (w3d->map[(int)(pos->x + dir->y * mv_speed)][(int)pos->y] == 0)
			pos->x += dir->y * mv_speed;
		if (w3d->map[(int)pos->x][(int)(pos->y - dir->x * mv_speed)] == 0)
			pos->y -= dir->x * mv_speed;
	}
}

void			edit_direction(t_wolf3d *w3d, t_ptd *dir, t_ptd *p)
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
** void edit_direction(); is not static because
** she's called in mouse_wolf3d in wolf_hook.c
*/

void			ft_edit_wolf3d(t_wolf3d *w3d)
{
	if (w3d->key1 == 49 || w3d->key2 == 49 || w3d->key3 == 49)
		ft_init_rc(w3d);
	edit_backfront(w3d, &w3d->r.pos, &w3d->r.dir);
	edit_lateral(w3d, &w3d->r.pos, &w3d->r.dir);
	edit_direction(w3d, &w3d->r.dir, &w3d->r.plane);
}
