/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:54:39 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/10 12:10:22 by cchameyr         ###   ########.fr       */
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
			ft_putstr("\n\033[31mERROR:\033[0m\nLeft of spawn is empty\n");
			return (0);
		}
		if (s_pos.x < 1)
		{
			ft_putstr("\n\033[31mERROR:\033[0m\n");
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
		ft_putstr("\n\033[31mERROR:\033[0m\n");
		ft_putstr("Position of spawn can't be on the last line\n");
		return (0);
	}
	if (w3d->start_pos.y > w3d->len_map[(int)w3d->start_pos.x - 1])
	{
		ft_putstr("\n\033[31mERROR:\033[0m\nTop of spawn is empty\n");
		return (0);
	}
	if (w3d->start_pos.y > w3d->len_map[(int)w3d->start_pos.x + 1])
	{
		ft_putstr("\n\033[31mERROR:\033[0m\nBottom of spawn is empty\n");
		return (0);
	}
	if ((int)w3d->start_pos.y == w3d->len_map[(int)w3d->start_pos.x] - 1)
	{
		ft_putstr("\n\033[31mERROR:\033[0m\nRight of spawn is empty\n");
		return (0);
	}
	return (1);
}

int		ft_error(int nb_spawn, int y, int max_x)
{
	if (nb_spawn > 1)
	{
		ft_putstr("\n\033[31mERROR:\033[0m\nToo much spawn\n");
		return (0);
	}
	else if (nb_spawn < 1)
	{
		ft_putstr("\n\033[31mERROR:\033[0m\nNo spawn\n");
		ft_putstr("Character spawn is 'x'\n");
		return (0);
	}
	else if (y < 3)
	{
		ft_putstr("\n\033[31mERROR:\033[0m\nMap is bad formated\n");
		ft_putstr("Number of LINE must be > 3\n");
		return (0);
	}
	else if (max_x < 3)
	{
		ft_putstr("\n\033[31mERROR:\033[0m\nMap is bad formated\n");
		ft_putstr("Number of COLON must be > 3\n");
		return (0);
	}
	return (1);
}

int		ft_error_line(t_pt p, int code)
{
	if (code == 0)
		ft_putstr("\n\033[31mERROR\n\033[0mBad character\n");
	ft_putstr("LINE : ");
	ft_putnbr(p.y);
	ft_putstr(" COLON : ");
	ft_putnbr(p.x);
	ft_putchar('\n');
	return (0);
}
