/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:09:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/28 11:22:53 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		edit_backfront(t_wolf3d *w3d, t_ptd *pos, t_ptd *dir)
{
	double		mv_speed;

	if (w3d->scanvalue[SDL_SCANCODE_W] == 1)
	{
		mv_speed = ((w3d->d.dt * 5) * (w3d->scanvalue[SDL_SCANCODE_LCTRL] == 1 ?
		0.2 : 1)) * (w3d->scanvalue[SDL_SCANCODE_LSHIFT] == 1 ? 2 : 1);
		if (w3d->map[(int)(pos->x + dir->x * mv_speed)][(int)pos->y] == 0)
			pos->x += w3d->r.dir.x * mv_speed;
		if (w3d->map[(int)pos->x][(int)(pos->y + dir->y * mv_speed)] == 0)
			pos->y += dir->y * mv_speed;
	}
	else if (w3d->scanvalue[SDL_SCANCODE_S] == 1)
	{
		mv_speed = ((w3d->d.dt * 5) * (w3d->scanvalue[SDL_SCANCODE_LCTRL] == 1 ?
		0.2 : 1)) * (w3d->scanvalue[SDL_SCANCODE_LSHIFT] == 1 ? 2 : 1);
		if (w3d->map[(int)(pos->x - dir->x * mv_speed)][(int)pos->y] == 0)
			pos->x -= dir->x * mv_speed;
		if (w3d->map[(int)pos->x][(int)(pos->y - dir->y * mv_speed)] == 0)
			pos->y -= dir->y * mv_speed;
	}
}

static void		edit_lateral(t_wolf3d *w3d, t_ptd *pos, t_ptd *dir)
{
	double		mv_speed;

	if (w3d->scanvalue[SDL_SCANCODE_A] == 1)
	{
		mv_speed = (w3d->d.dt * 5) * (w3d->scanvalue[SDL_SCANCODE_LCTRL] == 1 ?
		0.2 : 1);
		if (w3d->map[(int)(pos->x - dir->y * mv_speed)][(int)pos->y] == 0)
			pos->x -= dir->y * mv_speed;
		if (w3d->map[(int)pos->x][(int)(pos->y + dir->x * mv_speed)] == 0)
			pos->y += dir->x * mv_speed;
	}
	if (w3d->scanvalue[SDL_SCANCODE_D] == 1)
	{
		mv_speed = (w3d->d.dt * 5) * (w3d->scanvalue[SDL_SCANCODE_LCTRL] == 1 ?
		0.2 : 1);
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

//	rot_speed = w3d->d.dt * 3 * w3d->diff_x;
	if (w3d->scanvalue[SDL_SCANCODE_RIGHT] == 1)
	{
		rot_speed = w3d->d.dt * 3;
		old_dirx = dir->x;
		dir->x = dir->x * cos(-rot_speed) - dir->y * sin(-rot_speed);
		dir->y = old_dirx * sin(-rot_speed) + dir->y * cos(-rot_speed);
		old_planex = p->x;
		p->x = p->x * cos(-rot_speed) - p->y * sin(-rot_speed);
		p->y = old_planex * sin(-rot_speed) + p->y * cos(-rot_speed);
	}
	else if (w3d->scanvalue[SDL_SCANCODE_LEFT] == 1)
	{
		rot_speed = w3d->d.dt * 3;
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
	if (w3d->scanvalue[SDL_SCANCODE_SPACE] == 1)
		ft_init_rc(w3d);
	edit_backfront(w3d, &w3d->r.pos, &w3d->r.dir);
	edit_lateral(w3d, &w3d->r.pos, &w3d->r.dir);
	edit_direction(w3d, &w3d->r.dir, &w3d->r.plane);
}
