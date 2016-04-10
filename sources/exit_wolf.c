/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 11:29:32 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/10 12:23:47 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_exit_1(t_wolf3d *w3d)
{
	ft_memdel((void **)&w3d);
	exit(0);
}

void			ft_exit_wolf3d(t_wolf3d *w3d, const int exit_code)
{
	if (exit_code == 1)
		ft_exit_1(w3d);
	else if (exit_code == 2)
	{
		ft_putstr("Bad file\n");
		ft_exit_1(w3d);
	}
}
