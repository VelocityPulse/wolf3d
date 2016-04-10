/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 21:36:00 by                   #+#    #+#             */
/*   Updated: 2016/04/10 22:28:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		dda_normal_map(t_raycasting *r, t_wolf3d *w3d, int *x, int *y)
{
	while (w3d->map[*x][*y])
	{
		if (r->side_distx < r->side_disty)
		{
			r->side_distx += r->delta_distx;
			*x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_disty += r->delta_disty;
			*y += r->step_y;
			r->side = 1;
		}
	}
	return (w3d->map[*x][*y]);
}

int		dda_def_map(t_raycasting *r, t_wolf3d *w3d, int *x, int *y)
{
	while (w3d->def_map[*x][*y] == 0)
	{
		if (r->side_distx < r->side_disty)
		{
			r->side_distx += r->delta_distx;
			*x = *x + r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_disty += r->delta_disty;
			*y = *y + r->step_y;
			r->side = 1;
		}
	}
	return (w3d->def_map[*x][*y]);
}
