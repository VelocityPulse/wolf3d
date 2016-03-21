/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:06:31 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/21 17:57:03 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

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
	static int		x = 0;
	static int		y = W_HEIGHT / 2;
	struct timeval		t1;
	struct timeval		t2;
	double				elipsedTime;
	int					lolol = 0;

	gettimeofday(&t1, NULL);
	x = -1;
	ft_reset_image(w3d->mlx, 0);
	if (w3d->key != -1)
	{
		while (++x < W_WIDTH)
			ft_draw_pixel(w3d->mlx, 0xffffff, ft_make_pt(x, y));
		while (lolol < 5000000)
			lolol++;
	}
	ft_flush_image(w3d->mlx);
	gettimeofday(&t2, NULL);
	elipsedTime = (t2.tv_sec - t1.tv_sec) * 1000;
	elipsedTime += (t2.tv_usec - t1.tv_usec) / 1000;
	printf("%f\n", elipsedTime);
	return (0);
}
