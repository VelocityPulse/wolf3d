/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:45:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/31 14:34:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_wolf3d(t_wolf3d *w3d)
{
	ft_reset_image(w3d->mlx, 0);
	t_raycasting	r;

	int		x;
	double	rayDirX;
	double	rayDirY;
	double	rayPosX;
	double	rayPosY;
	double	cameraX;
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
	r = w3d->r;

	x = -1;
	while (++x < W_WIDTH)
	{
		cameraX = 2 * x / (double)W_WIDTH - 1;
		rayPosX = r.posX;
		rayPosY = r.posY;
		rayDirX = r.dirX + r.planeX * cameraX;
		rayDirY = r.dirY + r.planeY * cameraX;
		mapX = (int)round(rayPosX);
		mapY = (int)round(rayPosY);

		deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

		// calculate step
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (rayPosX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1 - rayPosX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (rayPosY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1 - rayPosY) * deltaDistY;
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
			perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;

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
