/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:45:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/11 16:21:58 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"


#define mapWidth 24
#define mapHeight 24

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

static void			calculate_line(t_raycasting *r, int *start, int *end)
{
	int			line_height;
	double		perp_wall_dist;

	if (r->side == 0)
		perp_wall_dist = (r->map_x - r->ray_posx + (1 - r->step_x) / 2) / r->ray_dirx;
	else
		perp_wall_dist = (r->map_y - r->ray_posy + (1 - r->step_y) / 2) / r->ray_diry;

	line_height = (int)(W_HEIGHT / perp_wall_dist);

	*start = -line_height / 2 + W_HEIGHT / 2;
	if (*start < 0)
		*start = 0;
	*end = line_height / 2 + W_HEIGHT / 2;
	if (*end >= W_HEIGHT)
		*end = W_HEIGHT - 1;
}

void			ft_wolf3d(t_wolf3d *w3d)
{

	t_raycasting	r;
	int		x;
	double	cameraX;
	int		line_start;
	int		line_end;
	int		color;
	int val;

	ft_edit_wolf3d(w3d);
	ft_reset_wolf_horizon(w3d);
	r = w3d->r;
	x = -1;
	while (++x < W_WIDTH)
	{
		init_ray(&r, x);
		calculate_step(&r);
		if (w3d->default_map == true)
			val = dda_def_map(&r, w3d, &r.map_x, &r.map_y);
		else
			val = dda_normal_map(&r, w3d, &r.map_x, &r.map_y);
		calculate_line(&r, &line_start, &line_end);
		if (val == 1)
			color = 0x555555;
		else if (val == 2)
			color = 0x00ff00;
		else if (val == 3)
			color = 0xff0000;
		else if (val == 4)
			color = 0x0000ff;
		else
			color = 0x0f0f00;
		if (r.side == 1)
		{
			t_rgb c;
			c = ft_get_rgb(color);
			c.r /= 2;
			c.g /= 2;
			c.b /= 2;
			color = ft_get_hexa(c);
		}
		ft_draw_line(ft_make_line(x, line_start, x, line_end), w3d->mlx, color);
	}
	ft_flush_image(w3d->mlx);
}
