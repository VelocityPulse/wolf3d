/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:45:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/22 17:32:17 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		calculate_step(t_raycasting *r)
{
	if (r->ray_dirx < 0)
	{
		r->step_x = -1;
		r->side_distx = (r->ray_posx - r->map_x) * r->delta_distx;
	}
	else
	{
		r->step_x = 1;
		r->side_distx = (r->map_x + 1 - r->ray_posx) * r->delta_distx;
	}
	if (r->ray_diry < 0)
	{
		r->step_y = -1;
		r->side_disty = (r->ray_posy - r->map_y) * r->delta_disty;
	}
	else
	{
		r->step_y = 1;
		r->side_disty = (r->map_y + 1 - r->ray_posy) * r->delta_disty;
	}
}

static void		init_ray(t_raycasting *r, int x)
{
	double		camera_x;

	camera_x = 2 * x / (double)W_WIDTH - 1;
	r->ray_posx = r->pos.x;
	r->ray_posy = r->pos.y;
	r->ray_dirx = r->dir.x + r->plane.x * camera_x;
	r->ray_diry = r->dir.y + r->plane.y * camera_x;
	r->map_x = (int)r->ray_posx;
	r->map_y = (int)r->ray_posy;
	r->delta_distx = sqrt(1 + (r->ray_diry * r->ray_diry) /
			(r->ray_dirx * r->ray_dirx));
	r->delta_disty = sqrt(1 + (r->ray_dirx * r->ray_dirx) /
			(r->ray_diry * r->ray_diry));
}

static int		dda(t_raycasting *r, t_wolf3d *w3d, int *x, int *y)
{
	while (w3d->map[*x][*y] == 0)
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

static void		calculate_line(t_raycasting *r, int *start, int *end, double sq)
{
	if (r->side == 0)
		r->perp_wall_dist = (r->map_x - r->ray_posx +
				(1 - r->step_x) / 2) / r->ray_dirx;
	else
		r->perp_wall_dist = (r->map_y - r->ray_posy +
				(1 - r->step_y) / 2) / r->ray_diry;
	r->line_height = (int)(W_HEIGHT / r->perp_wall_dist);
	*start = (-r->line_height / 2 + W_HEIGHT / 2) - (sq == 1 ? 0 : 120);
	if (*start < 0)
		*start = 0;
	*end = (r->line_height / 2 + W_HEIGHT / 2) - (sq == 1 ? 0 : 120);
	if (*end >= W_HEIGHT)
		*end = W_HEIGHT - 1;
}

void			ft_wolf3d(t_wolf3d *w3d)
{
	t_raycasting	*r;
	int				x;
	int				line_start;
	int				line_end;

	ft_edit_wolf3d(w3d);
	ft_reset_wolf_horizon(w3d, w3d->key_squat);
	r = &w3d->r;
	x = -1;
	while (++x < W_WIDTH)
	{
		init_ray(r, x);
		calculate_step(r);
		r->val = dda(r, w3d, &r->map_x, &r->map_y);
		calculate_line(r, &line_start, &line_end, w3d->key_squat);
		ft_trace(w3d, line_start, line_end, x);
	}
	ft_flush_image(w3d->mlx);
}
