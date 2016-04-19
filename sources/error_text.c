/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:00:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/19 18:04:35 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		ft_check_pos_spawn(t_wolf3d *w3d, int *max_x, t_pt p, int spwn)
{
	t_ptd	s_pos;

	s_pos = w3d->start_pos;
	*max_x = *max_x < p.x ? p.x : *max_x;
	if (spwn == 1)
	{
		if (s_pos.y < 1)
		{
			ft_putstr("Left of spawn is empty");
			return (0);
		}
		if (s_pos.x < 1)
		{
			ft_putstr("Position of spawn can't be on the first line\n");
			return (0);
		}
	}
	return (1);
}

int		ft_check_pos_spawn3(t_wolf3d *w3d)
{
	if (w3d->start_pos.x >= w3d->height - 1)
	{
		ft_putstr("Position of spawn can't be on the last line\n");
		return (0);
	}
	if (w3d->start_pos.y > w3d->len_map[(int)w3d->start_pos.x - 1])
	{
		ft_putstr("Top of spawn is empty\n");
		return (0);
	}
	if (w3d->start_pos.y > w3d->len_map[(int)w3d->start_pos.x + 1])
	{
		ft_putstr("Bottom of spawn is empty\n");
		return (0);
	}
	if ((int)w3d->start_pos.y == w3d->len_map[(int)w3d->start_pos.x] - 1)
	{
		ft_putstr("Right of spawn is empty\n");
		return (0);
	}
	return (1);
}

int		ft_error(int nb_spawn, int y, int max_x)
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
		ft_putstr("Map is bad formated\nNumber of LINE must be > 3\n");
		return (0);
	}
	else if (max_x < 3)
	{
		ft_putstr("map is bad formated\nNumber of COLON must be > 3\n");
		return (0);
	}
	return (1);
}

int		ft_error_line(t_pt p, int code)
{
	if (code == 0)
		ft_putstr("Bad character\n");
	ft_putstr("LINE : ");
	ft_putnbr(p.y);
	ft_putstr(" COLON : ");
	ft_putnbr(p.x);
	ft_putchar('\n');
	return (0);
}
