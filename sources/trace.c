/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:11:57 by                   #+#    #+#             */
/*   Updated: 2016/05/03 12:03:00 by cchameyr         ###   ########.fr       */
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
		ft_memcpy(var->data + pos, &color, var->octet);
		pos += var->width;
	}
	return (pos);
}

int				ft_trace_top(t_trace_var *var, int x, int l_start, int octet)
{
	int 	position;
	int		color;
	int		o;
	void	*data;
	int		width;

	position = x * octet;
	color = 0x44CCFF;
	data = var->data;
	width = var->width;
	o = -1;
	while (++o < l_start)
	{
		ft_memcpy(data + position, &color, octet);
		position += width;
	}
	return (position);
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
	while (++line_start <= var->mlx_height)
	{
		if (!(pos < 0 || pos > max_size))
			ft_memcpy(data + pos, &color, octet);
		pos += width;
	}
}

/*
** ft_trace_bot(); and ft_trace_top(); aren't static because
** they called in ft_trace_monocolor(); in trace_monocolor.c
*/

void			ft_trace(t_wolf3d *w3d, int line_start, int line_end, int x)
{
	t_raycasting	*r;
	long int		position;
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
		ft_trace_monocolor(w3d, line_start, line_end, x);
}
