/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 12:16:02 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/20 17:55:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static int		ft_check_spawn(char *n, int *spawn, t_wolf3d *w3d, t_pt p)
{
	static int		space = 0;

	if (*n == ' ')
		space++;
	else
		space = 0;
	if (space > 1)
	{
		ft_putstr("\nERROR:\nToo much space ");
		return (ft_error_line(p, 1));
	}
	if (*n == 'x' || *n == 'X')
	{
		*spawn = *spawn + 1;
		w3d->start_pos = ft_make_ptd(p.y - 0.5, p.x - 0.30);
		*n = '0';
	}
	return (1);
}

int				ft_check_map(t_wolf3d *w3d, t_lstline *l, int max_x, int s)
{
	t_pt		p;
	int			cx;

	p.y = 0;
	while (l && (++p.y) && (p.x = -1))
	{
		cx = 1;
		while (l->line[++p.x])
		{
			if (l->line[p.x] == ' ')
				cx++;
			if (!ft_check_spawn(&l->line[p.x], &s, w3d, ft_make_pt(cx, p.y)))
				return (0);
			if (!(l->line[p.x] >= '0' && l->line[p.x] <= '9') &&
					l->line[p.x] != ' ')
				return (ft_error_line(p, 0));
			if (ft_check_pos_spawn(w3d, &max_x, p, s) == 0)
				return (0);
		}
		l = l->next;
	}
	return (ft_error(s, p.y, max_x));
}
