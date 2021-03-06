/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_complete_case.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:09:02 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/03 12:09:27 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_complete_case2(t_wolf3d *w3d)
{
	t_pt	p;

	p.y = 0;
	while (++p.y < w3d->height)
	{
		p.x = -1;
		while (++p.x < w3d->len_map[p.y])
		{
			if (p.x >= w3d->len_map[p.y - 1])
			{
				if (w3d->map[p.y][p.x] == 0)
					w3d->map[p.y][p.x] = 1;
			}
			if (p.y < w3d->height - 1)
			{
				if (p.x >= w3d->len_map[p.y + 1])
				{
					if (w3d->map[p.y][p.x] == 0)
						w3d->map[p.y][p.x] = 1;
				}
			}
		}
	}
}

void	ft_complete_case(t_wolf3d *w3d)
{
	t_pt	p;

	ft_putstr("Completing void case...\n");
	p.y = -1;
	while (++p.y < w3d->height)
	{
		p.x = -1;
		if (p.y == 0 || p.y == w3d->height - 1)
		{
			while (++p.x < w3d->len_map[p.y])
			{
				if (w3d->map[p.y][p.x] == 0)
					w3d->map[p.y][p.x] = 1;
			}
		}
		if (w3d->len_map[p.y] > 0)
		{
			if (w3d->map[p.y][w3d->len_map[p.y] - 1] == 0)
				w3d->map[p.y][w3d->len_map[p.y] - 1] = 1;
		}
		if (w3d->map[p.y][0] == 0)
			w3d->map[p.y][0] = 1;
	}
	ft_complete_case2(w3d);
}
