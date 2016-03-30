/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:45:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/30 17:18:11 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_wolf3d(t_wolf3d *w3d)
{
	ft_reset_image(w3d->mlx, 0);
	t_raycasting	r;

	r = w3d->r;

	int		x;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;

	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;

	int		stepX;
	int		stepY;
	int		side;

	int		lineHeight;
	int		drawStart;
	int		drawEnd;

	int		color;

	ft_edit_wolf3d(w3d);
	x = -1;
	while (++x < W_WIDTH)
	{
		r.cameraX = 2 * x / (double)W_WIDTH - 1;
		r.rayPosX = r.posX;
		r.rayPosY = r.posY;
		rayDirX = r.dirX + r.planeX * r.cameraX;
		rayDirY = r.dirY + r.planeY * r.cameraX;
		mapX = (int)r.rayPosX;
		mapY = (int)r.rayPosY;

		deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

		// calculate step
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (r.rayPosX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1 - r.rayPosX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (r.rayPosY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1 - r.rayPosY) * deltaDistY;
		}

		// DDA
		while (w3d->map.map[(mapY - 1) * w3d->map.size.x + (mapX - 1)] == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
		}

		// correct fisheye
		if (side == 0)
			perpWallDist = (mapX - r.rayPosX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - r.rayPosY + (1 - stepY) / 2) / rayDirY;

		// calculate height of column
		lineHeight = (int)(W_HEIGHT / perpWallDist);
		
		drawStart = -lineHeight / 2 + W_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + W_HEIGHT / 2;
		if (drawEnd >= W_HEIGHT)
			drawEnd = W_HEIGHT - 1;

		// correct brightness
		if (side == 1)
			color = 0x555555;
		else
			color = 0x101010;

		ft_draw_line(ft_make_line(x, drawStart, x, drawEnd), w3d->mlx, color);

	}
	ft_flush_image(w3d->mlx);
}
