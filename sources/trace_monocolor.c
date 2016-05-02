/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_monocolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:24:13 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/02 13:00:31 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static char		ft_cardinal(t_raycasting *r, int side)
{
	if (side == 0)
	{
		if ()
			
		else if ()
			
	}
	else if (side == 1)
	{
		if ()
			
		else if ()
			
	}
}

void			ft_trace_monocolor(t_wolf3d *w3d, int lstart, int lend, int x)
{
	t_trace_var		*var;

	var = &w3d->var;
	var->cardinal = ft_cardinal(var->r, var->r->side);
}
