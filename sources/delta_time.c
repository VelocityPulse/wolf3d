/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:56:26 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/11 11:11:33 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/delta_time.h"

void	get_deltatime(t_delta *d, const int fps_mode)
{
	static double		timer = 0;

	d->elipsed_time = (d->t2.tv_sec - d->t1.tv_sec) * 1000;
	d->elipsed_time += (d->t2.tv_usec - d->t1.tv_usec) / 1000;
	d->dt = d->elipsed_time / 1000;
	d->fps = 1 / d->dt;
	if (fps_mode)
	{
		timer += d->dt;
		if (timer >= 0.5)
		{
			ft_putstr("FPS : ");
			ft_putnbr(d->fps);
			ft_putchar('\n');
			timer = 0;
		}
	}
}

void	start_delta(t_delta *d)
{
	gettimeofday(&d->t1, NULL);
}

void	end_delta(t_delta *d)
{
	gettimeofday(&d->t2, NULL);
}
