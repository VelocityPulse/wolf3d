/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:47:13 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/13 12:34:23 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_reset_wolf_horizon(t_wolf3d *w3d, double squat)
{
	int		octet;
	int		position;
	char	*img;
	int		max_size;
	int		color;

	img = w3d->mlx->mlx_img->data;
	octet = w3d->mlx->mlx_img->bpp / 8;
	max_size = w3d->mlx->mlx_img->max_size;
	position = 0;
	color = 0x33CCFF;
	squat = (squat == 1 ? 0 : 480);
	while (position < (max_size / 2) - squat * W_WIDTH)
	{
		ft_memcpy(img + position, &color, octet);
		position += octet;
	}
	color = 0x996633;
	while (position < max_size)
	{
		ft_memcpy(img + position, &color, octet);
		position += octet;
	}
}
