/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:08:41 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/24 14:04:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static int		except_press(int keycode, t_wolf3d *w3d)
{
	if (keycode == 53)
		ft_exit_wolf3d(w3d, 3);
	if (keycode == 257)
	{
		w3d->key_sprint = 2;
		return (1);
	}
	if (keycode == 256)
	{
		w3d->key_squat = 0.2;
		return (1);
	}
	if (keycode == 46)
	{
		ft_display_map(w3d);
		return (1);
	}
	return (0);
}

int				press_wolf3d(int keycode, t_wolf3d *w3d)
{
	if (except_press(keycode, w3d) == 1)
		return (0);
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

int				unpress_wolf3d(int keycode, t_wolf3d *w3d)
{
	if (keycode == 257)
		return (w3d->key_sprint = 1);
	if (keycode == 256)
		return (w3d->key_squat = 1);
	if (w3d->key1 == keycode)
		w3d->key1 = -1;
	if (w3d->key2 == keycode)
		w3d->key2 = -1;
	if (w3d->key3 == keycode)
		w3d->key3 = -1;
	return (0);
}

int				mouse_wolf3d(int x, int y, t_wolf3d *w3d)
{
	static double	old_x = 0;

	if (old_x == 0)
		old_x = (double)x;
	if (x != old_x)
	{
		w3d->diff_x = (double)(x - old_x) / 10;
		if (w3d->diff_x < 0.0f)
		{
			w3d->diff_x = -w3d->diff_x;
			press_wolf3d(123, w3d);
			edit_direction(w3d, &w3d->r.dir, &w3d->r.plane);
			unpress_wolf3d(123, w3d);
		}
		else if (w3d->diff_x > 0.0f)
		{
			press_wolf3d(124, w3d);
			edit_direction(w3d, &w3d->r.dir, &w3d->r.plane);
			unpress_wolf3d(124, w3d);
		}
	}
	old_x = x;
	w3d->diff_x = 1;
	(void)y;
	return (0);
}

int				loop_wolf3d(t_wolf3d *w3d)
{
	start_delta(&w3d->d);
	ft_wolf3d(w3d);
	end_delta(&w3d->d);
	get_delta(&w3d->d, w3d->fps_mode);
	return (0);
}
