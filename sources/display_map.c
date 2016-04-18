/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 21:45:46 by                   #+#    #+#             */
/*   Updated: 2016/04/18 22:36:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_display1(t_wolf3d *w3d)
{
	t_pt	p;

	p.y = -1;
	while (++p.y < w3d->height)
	{
		p.x = -1;
		while (++p.x < w3d->len_map[p.y])
		{
			ft_putnbr(w3d->map[p.y][p.x]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

static void		ft_display2(t_wolf3d *w3d)
{
	t_pt	p;

	p.y = -1;
	while (++p.y < 15)
	{
		p.x = -1;
		while (++p.x < 20)
		{
			ft_putnbr(w3d->map[p.y][p.x]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void			ft_display_final_map(t_wolf3d *w3d)
{
	if (w3d->default_map == false)
		ft_display1(w3d);
	if (w3d->default_map == true)
		ft_display2(w3d);
}
