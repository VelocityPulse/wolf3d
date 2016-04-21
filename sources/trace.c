/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:11:57 by                   #+#    #+#             */
/*   Updated: 2016/04/21 15:58:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_trace(t_wolf3d *w3d, int line_start, int line_end, int x)
{
	t_raycasting	*r;
	t_texture		*t;
	int				y;
	int				d;
	double			wall_x;
	int				tex_x;
	int				 color;

	r = &w3d->r;
	t = &w3d->t;
	if (r->side == 0)
		wall_x = r->ray_posy + r->perp_wall_dist * r->ray_diry;
	else
		wall_x = r->ray_posx + r->perp_wall_dist * r->ray_dirx;
	wall_x -= floor(wall_x);
	if (r->val >= 30 && r->val <= 37)
	{
		tex_x = (int)(wall_x * (double)t->list[r->val - 30]->size.x);
		if (r->side == 0 && r->ray_dirx > 0)
			tex_x = t->list[r->val - 30]->size.x - tex_x - 1;
		if (r->side == 1 && r->ray_diry < 0)
			tex_x = t->list[r->val - 30]->size.x - tex_x - 1;
		y = line_start - 1;
		while (++y < line_end)
		{
			d = y * 256 - W_HEIGHT * 128 + r->line_height * 128;
			int tex_y = ((d * t->list[r->val - 30]->size.y) / r->line_height) / 256;
			color = ft_get_pixel_image(t->list[r->val - 30], ft_make_pt(tex_x, tex_y));
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
