/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:06:31 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/01 17:40:55 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		get_deltatime(t_delta *d)
{
	static double		timer = 0;

	d->elipsedTime = (d->t2.tv_sec - d->t1.tv_sec) * 1000;
	d->elipsedTime += (d->t2.tv_usec - d->t1.tv_usec) / 1000;
	d->dt = d->elipsedTime / 1000;
	d->dt = d->dt < 0 ? -d->dt : d->dt;
	d->fps = 1 / d->dt;
	if (1)
	{
		timer += d->elipsedTime / 1000;
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
	if (w3d->key1 == -1 && w3d->key2 != keycode)
		w3d->key1 = keycode;
	else if (w3d->key2 == -1 && w3d->key1 != keycode)
		w3d->key2 = keycode;
	return (0);
}

int		unpress_wolf3d(int keycode, t_wolf3d *w3d)
{
	(void)keycode;
	if (w3d->key1 == keycode)
		w3d->key1 = -1;
	if (w3d->key2 == keycode)
		w3d->key2 = -1;
	return (0);
}

int		loop_wolf3d(t_wolf3d *w3d)
{
	gettimeofday(&w3d->d.t1, NULL);

	ft_wolf3d(w3d);

	gettimeofday(&w3d->d.t2, NULL);
	get_deltatime(&w3d->d);
	return (0);
}
