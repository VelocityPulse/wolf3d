/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:11:57 by                   #+#    #+#             */
/*   Updated: 2016/04/29 14:59:06 by                  ###   ########.fr       */
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

int				ft_trace_top(t_trace_var *var, int x, int line_start, int octet)
{
	int 	position;
	int		color;
	int		o;
	void	*data;
	int		width;
//	int		max_size;

	position = x * octet;
	color = 0x44CCFF;
	data = var->data;
	width = var->width;
//	max_size = var->max_size;
	o = -1;
	while (++o < line_start)
	{
//		if (!(position < 0 || position > max_size))
			ft_memcpy(data + position, &color, octet);
		position += width;
	}
	return (position);
}

static int		ft_trace_tex(t_trace_var *var, int pos, int l_h, int size_y)
{
	int			tmp;
	int			*colon;
	int			tex_y;
	int			color;
	long int	d;

	size_y = var->t->list_img[var->tex_val]->size.y;
	colon = var->t->list_text[var->tex_val]
	[ft_tex_x(var->r, var->t->list_img[var->tex_val]->size.x)];
	tmp = var->line_start + (*var->key_squat == 1 ? 0 : 120);
	while (++var->line_start < var->line_end)
	{
		d = ++tmp * 256 - W_HEIGHT * 128 + l_h * 128;
		tex_y = ((d * size_y) / l_h) / 256;
		color = colon[tex_y];
//		if (!(pos < 0 || pos > var->max_size))
			ft_memcpy(var->data + pos, &color, var->octet);
		pos += var->width;
	}
	return (pos);
}

void			ft_trace_bot(t_trace_var *var, int pos, int line_start)
{
	int 	octet;
	int		color;
	void	*data;
	int		width;
	int		max_size;

	color = 0x667882;
	data = var->data;
	octet = var->octet;
	width = var->width;
	max_size = var->max_size;
	while (++line_start < var->mlx_height)
	{
		if (!(pos < 0 || pos > max_size))
			ft_memcpy(data + pos, &color, octet);
		pos += width;
	}

}

void			ft_trace(t_wolf3d *w3d, int line_start, int line_end, int x)
{
	t_raycasting	*r;
	int				color;

	int				width;
	long int		position;
	void			*data;
	t_trace_var		*var;

	r = &w3d->r;
	var = &w3d->var;
	if (r->val >= 30 && r->val <= 37)
	{
		w3d->var.tex_val  = w3d->r.val - 30;
		position = ft_trace_top(var, x, var->line_start, var->octet);
		position = ft_trace_tex(var, position, var->line_height, 0);
		ft_trace_bot(var, position, var->line_start);
	}
	else
	{
		data = var->data;
		width = var->width;
		position = ft_trace_top(var, x, var->line_start, var->octet);
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
		while (++line_start < line_end)
		{
			if (!(position < 0 || position > var->max_size))
				ft_memcpy(data + position, &color, var->octet);
			position += width;
		}
		ft_trace_bot(var, position, var->line_start);
	}
}
