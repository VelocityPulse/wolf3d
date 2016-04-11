/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:45:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/11 15:52:10 by cchameyr         ###   ########.fr       */
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
	int		camera_x;

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

void			ft_wolf3d(t_wolf3d *w3d)
{
	//	ft_reset_image(w3d->mlx, 0);
	ft_reset_wolf_horizon(w3d);
	t_raycasting	r;

	int		x;
	double	cameraX;

	double	perpWallDist;

	int		lineHeight;
	int		drawStart;
	int		drawEnd;

	int		color;

	ft_edit_wolf3d(w3d);
	r = w3d->r;

	x = -1;
	while (++x < W_WIDTH)
	{

		init_ray(&r, x);
		// calculate step
		calculate_step(&r);

		// DDA
		int val;
		if (w3d->default_map == true)
			val = dda_def_map(&r, w3d, &r.map_x, &r.map_y);
		else
			val = dda_normal_map(&r, w3d, &r.map_x, &r.map_y);


		// correct fisheye
		if (r.side == 0)
			perpWallDist = (r.map_x - r.ray_posx + (1 - r.step_x) / 2) / r.ray_dirx;
		else
			perpWallDist = (r.map_y - r.ray_posy + (1 - r.step_y) / 2) / r.ray_diry;

		lineHeight = (int)(W_HEIGHT / perpWallDist);

		drawStart = -lineHeight / 2 + W_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + W_HEIGHT / 2;
		if (drawEnd >= W_HEIGHT)
			drawEnd = W_HEIGHT - 1;

		// correct brightness
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

		ft_draw_line(ft_make_line(x, drawStart, x, drawEnd), w3d->mlx, color);
	}
	ft_flush_image(w3d->mlx);
}
