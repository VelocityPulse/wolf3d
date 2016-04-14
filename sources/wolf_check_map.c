/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 12:16:02 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/14 15:49:57 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_check_spawn(char *n, int *spawn, t_wolf3d *w3d, t_pt p)
{
	static int		space = 0;

	if (*n == ' ')
		space++;
	else
		space = 0;
	if (space > 1)
	{
		ft_putstr("Too much space ");
		return (ft_error_line(p, 1));
	}
	if (*n == 'x' || *n == 'X')
	{
		*spawn = *spawn + 1;
		w3d->start_pos = ft_make_ptd(p.y - 0.5, p.x - 0.30);
		*n = '0';
	}
}

static int		ft_check_pos_spawn2(t_wolf3d *w3d, int cx, t_lstline **list)
{
	if (round(w3d->start_pos.y) == cx)
	{
		ft_putstr("Position of spawn can be the end line\n");
		return (0);
	}
	*list = (*list)->next;
	return (1);
}

int				ft_check_map(t_wolf3d *w3d, t_lstline *list)
{
	t_pt		p;
	int			cx;
	int			max_x;
	int			spawn;

	spawn = 0;
	p.y = 0;
	max_x = 0;
	while (list && (++p.y) && (p.x = -1))
	{
		cx = 1;
		while (list->line[++p.x])
		{
			if (list->line[p.x] == ' ')
				cx++;
			ft_check_spawn(&list->line[p.x], &spawn, w3d, ft_make_pt(cx, p.y));
			if (!(list->line[p.x] >= '0' && list->line[p.x] <= '9') &&
					list->line[p.x] != ' ')
				return (ft_error_line(p, 0));
			if (ft_check_pos_spawn(w3d, &max_x, p, spawn) == 0)
				return (0);
		}
		if (ft_check_pos_spawn2(w3d, cx, &list) == 0)
			return (0);
	}
	return (ft_error(w3d, spawn, p.y, max_x));
}
