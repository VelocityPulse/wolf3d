/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:45:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/10 22:27:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"


#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	ft_wolf3d(t_wolf3d *w3d)
{
//	ft_reset_image(w3d->mlx, 0);
	ft_reset_wolf_horizon(w3d);
	t_raycasting	r;

	int		x;
	double	rayDirX;
	double	rayDirY;
	double	rayPosX;
	double	rayPosY;
	double	cameraX;
	int		mapX;
	int		mapY;

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
		cameraX = 2 * x / (double)W_WIDTH - 1;
		rayPosX = r.pos.x;
		rayPosY = r.pos.y;
		rayDirX = r.dir.x + r.plane.x * cameraX;
		rayDirY = r.dir.y + r.plane.y * cameraX;
		mapX = (int)rayPosX;
		mapY = (int)rayPosY;

		r.delta_distx = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		r.delta_disty = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

		// calculate step
		if (rayDirX < 0)
		{
			r.step_x = -1;
			r.side_distx = (rayPosX - mapX) * r.delta_distx;
		}
		else
		{
			r.step_x = 1;
			r.side_distx = (mapX + 1 - rayPosX) * r.delta_distx;
		}
		if (rayDirY < 0)
		{
			r.step_y = -1;
			r.side_disty = (rayPosY - mapY) * r.delta_disty;
		}
		else
		{
			r.step_y = 1;
			r.side_disty = (mapY + 1 - rayPosY) * r.delta_disty;
		}

		// DDA
		int		val = dda_def_map(&r, w3d, &mapX, &mapY);
		// correct fisheye
		if (r.side == 0)
			perpWallDist = (mapX - rayPosX + (1 - r.step_x) / 2) / rayDirX;
		else
			perpWallDist = (mapY - rayPosY + (1 - r.step_y) / 2) / rayDirY;

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
