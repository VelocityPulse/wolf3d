/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 12:16:02 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/13 16:52:27 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_check_spawn(char *n, int *spawn, t_wolf3d *w3d, t_pt p)
{
	if (*n == 'x' || *n == 'X')
	{
		*spawn = *spawn + 1;
		w3d->start_pos = ft_make_ptd(p.y - 0.5, p.x - 0.30);
		*n = '0';
	}
}

static int		ft_error(const int nb_spawn, const int y)
{
	if (nb_spawn > 1)
	{
		ft_putstr("Too much spawn\n");
		return (0);
	}
	else if (nb_spawn < 1)
	{
		ft_putstr("No spawn\nCharacter spawn is 'x'\n");
		return (0);
	}
	else if (y < 3)
	{
		ft_putstr("Map is bad formated\nNumber of line must be > 3\n");
		return (0);
	}
	else
		return (1);
}

static int		ft_error_line(t_pt p)
{
	ft_putstr("Bad character\nLINE : ");
	ft_putnbr(p.y);
	ft_putstr(" COLON : ");
	ft_putnbr(p.x);
	ft_putchar('\n');
	return (0);
}

int				ft_check_map(t_wolf3d *w3d, t_lstline *list)
{
	t_pt		p;
	int			cx;
	int			spawn;

	spawn = 0;
	p.y = 0;
	while (list && (++p.y))
	{
		p.x = -1;
		cx = 1;
		while (list->line[++p.x])
		{
			if (list->line[p.x] == ' ')
				cx++;
			ft_check_spawn(&list->line[p.x], &spawn, w3d, ft_make_pt(cx, p.y));
			if (!(list->line[p.x] >= '0' && list->line[p.x] <= '9') &&
					list->line[p.x] != ' ')
					return (ft_error_line(p));
		}
		list = list->next;
	}
	return (ft_error(spawn, p.y));
}
