/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:06:31 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/08 12:15:27 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		get_deltatime(t_delta *d, int fps_mode)
{
	static double		timer = 0;

	d->elipsed_time = (d->t2.tv_sec - d->t1.tv_sec) * 1000;
	d->elipsed_time += (d->t2.tv_usec - d->t1.tv_usec) / 1000;
	d->dt = d->elipsed_time / 1000;
	d->dt = d->dt < 0 ? -d->dt : d->dt;
	d->fps = 1 / d->dt;
	if (fps_mode)
	{
		timer += d->elipsed_time / 1000;
		if (timer >= 0.5)
		{
			ft_putstr("FPS : ");
			ft_putnbr(d->fps);
			ft_putchar('\n');
			timer = 0;
		}
	}
}

int		press_wolf3d(int keycode, t_wolf3d *w3d)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 3 && w3d->fps_mode == 0)
	{
		ft_putstr("FPS = ON\n");
		w3d->fps_mode = 1;
		return (0);
	}
	else if (keycode == 3)
	{
		ft_putstr("FPS = OFF\n");
		w3d->fps_mode = 0;
		return (0);
	}
	if (w3d->key1 == -1 && w3d->key2 != keycode && w3d->key3 != keycode)
		w3d->key1 = keycode;
	else if (w3d->key2 == -1 && w3d->key1 != keycode && w3d->key3 != keycode)
		w3d->key2 = keycode;
	else if (w3d->key3 == -1 && w3d->key1 != keycode && w3d->key2 != keycode)
		w3d->key3 = keycode;

	return (0);
}

int		unpress_wolf3d(int keycode, t_wolf3d *w3d)
{
	if (w3d->key1 == keycode)
		w3d->key1 = -1;
	if (w3d->key2 == keycode)
		w3d->key2 = -1;
	if (w3d->key3 == keycode)
		w3d->key3 = -1;
	return (0);
}

int		mouse_wolf3d(int x, int y, t_wolf3d *w3d)
{
	static double	old_x = 0;

	if (x != old_x)
	{
		w3d->diff_x = (double)(x - old_x) / 15;
		if (w3d->diff_x < 0.0f)
		{
			w3d->diff_x = -w3d->diff_x;
			press_wolf3d(123, w3d);
			edit_direction(w3d, &w3d->r.pos, &w3d->r.dir, &w3d->r.plane);
			unpress_wolf3d(123, w3d);
		}
		else if (w3d->diff_x > 0.0f)
		{
			press_wolf3d(124, w3d);
			edit_direction(w3d, &w3d->r.pos, &w3d->r.dir, &w3d->r.plane);
			unpress_wolf3d(124, w3d);
		}
	}
	old_x = x;
	(void)y;
	w3d->diff_x = 1;
	return (0);
}

int		loop_wolf3d(t_wolf3d *w3d)
{
	gettimeofday(&w3d->d.t1, NULL);

	ft_wolf3d(w3d);

	gettimeofday(&w3d->d.t2, NULL);
	get_deltatime(&w3d->d, w3d->fps_mode);
	return (0);
}
