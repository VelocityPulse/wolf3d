/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:06:31 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/23 12:04:52 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		get_deltatime(t_delta *d)
{
	d->elipsedTime = (d->t2.tv_sec - d->t1.tv_sec) * 1000;
	d->elipsedTime = (d->t2.tv_usec - d->t1.tv_usec) / 1000;
	d->dt = d->elipsedTime / 1000;
}

int		press_wolf3d(int keycode, t_wolf3d *w3d)
{
	if (keycode == 53)
		exit(0);
	w3d->key = keycode;
	return (0);
}

int		unpress_wolf3d(int keycode, t_wolf3d *w3d)
{
	(void)keycode;
	w3d->key = -1;
	return (0);
}

int		loop_wolf3d(t_wolf3d *w3d)
{
	gettimeofday(&w3d->d.t1, NULL);
	
	ft_wolf3d_refresh(w3d);

	gettimeofday(&w3d->d.t2, NULL);
	get_deltatime(&w3d->d);
	return (0);
}
