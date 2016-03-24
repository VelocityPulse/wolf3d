/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:08:02 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/24 16:56:41 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_wall		ft_dist(t_map map, t_player player, float deg)
{
	t_wall		wall;
	t_pt		p;
	t_pt		var;
	float		err;
	float		a;

	p = ft_make_pt(player.pos.x, player.pos.y);
	err = 0;
	// if (deg == 0 || deg == 90 || deg == 180)
	if (deg > 0 && deg < 90)
		var = ft_make_pt(1, -1);
	else if (deg > 90 && deg < 180)
		var = ft_make_pt(-1, -1);
	else if (deg > 180 && deg < 270)
		var = ft_make_pt(-1, 1);
	else
		var = ft_make_pt(1, 1);
	a = 
	while (map.map[p.y * map.size.y + p.x] == 0)
	{
		err += a;
		
	}
	return (wall);
}
