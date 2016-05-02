/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_monocolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:24:13 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/02 17:48:09 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static char		ft_cardinal(t_raycasting *r, int side)
{
	if (side == 0)
	{
		if (r->ray_posx > r->map_x)
			return (_NORTH_);
		else if (r->ray_posx <= r->map_x)
			return (_SOUTH_);
	}
	else if (side == 1)
	{
		if (r->ray_posy > r->map_y)
			return (_EST_);
		else if (r->ray_posy <= r->map_y)
			return (_WEST_);
	}
	return (0);
}

static int		ft_select_color(int val)
{
	int color;

	if (val == 1)
		color = 0x555555;
	else if (val == 2)
		color = 0x00FF00;
	else if (val == 3)
		color = 0xFF0000;
	else if (val == 4)
		color = 0x0000FF;
	else if (val == 5)
		color = 0xB2119C;
	else if (val == 6)
		color = 0x0A4502;
	else if (val == 7)
		color = 0x6C6E47;
	else if (val == 8)
		color = 0xF07000;
	else if (val == 9)
		color = 0x57009A;
	else
		color = 0x0f0f0f;
	return (color);
}

void			ft_trace_monocolor(t_wolf3d *w3d, int lstart, int lend, int x)
{
	t_trace_var		*var;
	int				position;
	int				color;
	void			*data;
	int				width;

	var = &w3d->var;
	var->cardinal = ft_cardinal(var->r, var->r->side);
	position = ft_trace_top(var, x, var->line_start, var->octet);
	if (var->r->val >= 20 && var->r->val <= 24)
		var->r->val = (var->r->val - 19) + var->cardinal;
	color = ft_select_color(var->r->val);
	data = var->data;
	width = var->width;
	while (++lstart < lend)
	{
		if (!(position < 0 || position > var->max_size))
			ft_memcpy(data + position, &color, var->octet);
		position += width;
	}
	ft_trace_bot(var, position, var->line_end);
}
