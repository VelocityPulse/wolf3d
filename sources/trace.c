/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:11:57 by                   #+#    #+#             */
/*   Updated: 2016/04/21 18:11:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_trace(t_wolf3d *w3d, int line_start, int line_end, int x)
{
	t_raycasting	*r;
	t_texture		*t;
	int				y;
	int				size_x;
	int				size_y;
	int				d;
	double			wall_x;
	int				tex_x;
	int				line_height;
	int				 color;
	t_img			*tex;

	r = &w3d->r;
	t = &w3d->t;
	line_height = r->line_height;
	if (r->side == 0)
		wall_x = r->ray_posy + r->perp_wall_dist * r->ray_diry;
	else
		wall_x = r->ray_posx + r->perp_wall_dist * r->ray_dirx;
	wall_x -= floor(wall_x);
	if (r->val >= 30 && r->val <= 37)
	{
		tex = t->list[r->val - 30];
		size_x = tex->size.x;
		size_y = tex->size.y;
		tex_x = (int)(wall_x * (double)size_x);
		if (r->side == 0 && r->ray_dirx > 0)
			tex_x = size_x - tex_x - 1;
		if (r->side == 1 && r->ray_diry < 0)
			tex_x = size_x - tex_x - 1;
		y = line_start - 1;
		while (++y < line_end)
		{
			d = y * 256 - W_HEIGHT * 128 + line_height * 128;
			int tex_y = ((d * size_y) / line_height) / 256;
			color = ft_get_pixel_image(tex, ft_make_pt(tex_x, tex_y));
			if (r->side == 1)
			{
				t_rgb c;
				c = ft_get_rgb(color);
				c.r /= 2;
				c.g /= 2;
				c.b /= 2;
				color = ft_get_hexa(c);
			}
			ft_draw_pixel(w3d->mlx, color, ft_make_pt(x, y));
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
		ft_draw_line(ft_make_line(x, line_start, x, line_end), w3d->mlx, color);
		return ;
	}
}
