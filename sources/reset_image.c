/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:47:13 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/02 14:26:57 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_reset_wolf_horizon(t_wolf3d *w3d)
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
	while (position < max_size / 2)
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
