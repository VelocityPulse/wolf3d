/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:11:57 by                   #+#    #+#             */
/*   Updated: 2016/04/25 21:37:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static int		ft_tex_x(t_raycasting *r, int size_x)
{
	double	wall_x;
	int		tex_x;

	if (r->side == 0)
		wall_x = r->ray_posy + r->perp_wall_dist * r->ray_diry;
	else
		wall_x = r->ray_posx + r->perp_wall_dist * r->ray_dirx;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)size_x);
	if (r->side == 0 && r->ray_dirx > 0)
		tex_x = size_x - tex_x - 1;
	if (r->side == 1 && r->ray_diry < 0)
		tex_x = size_x - tex_x - 1;
	return (tex_x);
}

void			ft_trace(t_wolf3d *w3d, int line_start, int line_end, int x)
{
	t_raycasting	*r;
	t_texture		*t;
	int				size_y;
	long int				d;
	int				line_height;
	int				 color;
	int				tex_y;
	int				o = -1;
		int *colon;
		int	width;
		long int	position;
		void		*data;
		int			tmp;
int		sky = 0x44CCFF;
	int octet;
	int max_size;


	r = &w3d->r;
	t = &w3d->t;
	line_height = r->line_height;

	if (r->val >= 30 && r->val <= 37)
	{
		size_y = t->list_img[r->val - 30]->size.y;
		colon = t->list_text[r->val - 30][ft_tex_x(r, t->list_img[r->val - 30]->size.x)];
		position = x * w3d->mlx->mlx_img->octet;
		data = w3d->mlx->mlx_img->data;
		width = w3d->mlx->mlx_img->width;
		while (++o < line_start)
		{
			if (!(position < 0 || position > w3d->mlx->mlx_img->max_size))
				ft_memcpy(data + position, &sky, w3d->mlx->mlx_img->octet);
			position += width;
		}
		tmp = line_start + (w3d->key_squat == 1 ? 0 : 120);
		octet = w3d->mlx->mlx_img->octet;
		max_size = w3d->mlx->mlx_img->max_size;
		while (++line_start < line_end)
		{
			d = ++tmp * 256 - W_HEIGHT * 128 + line_height * 128;
			tex_y = ((d * size_y) / line_height) / 256;
				color = colon[tex_y];
				if (!(position < 0 || position > w3d->mlx->mlx_img->max_size))
					ft_memcpy(data + position, &color, w3d->mlx->mlx_img->octet);
			position += width;
		}
		color = 0x667882;
		while (++line_end < w3d->mlx->height)
		{
			if (!(position < 0 || position > w3d->mlx->mlx_img->max_size))
				ft_memcpy(data + position, &color, w3d->mlx->mlx_img->octet);
			position += width;
		}
	}
	else
	{
		if (r->val == 1)
			color = 0x555555;
		else if (r->val == 2)
			color = 0x00ff00;
		else if (r->val == 3)
			color = 0xff0000;
		else if (r->val == 4)
			color = 0x0000ff;
		else
			color = 0x0f0f00;
		if (r->side == 1)
		{
			t_rgb c;
			c = ft_get_rgb(color);
			c.r /= 2;
			c.g /= 2;
			c.b /= 2;
			color = ft_get_hexa(c);
		}
		position = x * w3d->mlx->mlx_img->octet;
		data = w3d->mlx->mlx_img->data;
		width = w3d->mlx->mlx_img->width;
		
		while (++o < line_start)
		{
			if (!(position < 0 || position > w3d->mlx->mlx_img->max_size))
				ft_memcpy(data + position, &sky, w3d->mlx->mlx_img->octet);
			position += width;
		}
		while (++line_start < line_end)
		{
			if (!(position < 0 || position > w3d->mlx->mlx_img->max_size))
				ft_memcpy(data + position, &color, w3d->mlx->mlx_img->octet);
			position += width;
		}
		color = 0x667882;
		while (++line_end < w3d->mlx->height)
		{
			if (!(position < 0 || position > w3d->mlx->mlx_img->max_size))
				ft_memcpy(data + position, &color, w3d->mlx->mlx_img->octet);
			position += width;
		}
		return ;
	}
}
