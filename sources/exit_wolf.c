/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 11:29:32 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/28 10:15:37 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_exit_1(t_wolf3d *w3d)
{
	ft_memdel((void **)&w3d);
	ft_putstr("Wolf3d :\tCLEAR\n\n");
	exit(0);
}

static void		ft_exit_2(t_wolf3d *w3d)
{
	int		i;

	i = -1;
	ft_putchar('\n');
	ft_clear_image(w3d->mlx, w3d->t);
	ft_clear_mlx(w3d->mlx);
	ft_putstr("mlx :\t\tCLEAR\n");
	while (++i < w3d->height)
		ft_memdel((void **)&w3d->map[i]);
	free(w3d->map);
	ft_putstr("Map tab :\tCLEAR\n");
	ft_memdel((void **)&w3d->len_map);
	ft_memdel((void **)&w3d);
	ft_putstr("Wolf3d :\tCLEAR\n\n");
	exit(0);
}

static void		ft_exit_3(t_wolf3d *w3d)
{
	int		i;

	i = -1;
	ft_putchar('\n');
	ft_clear_list_textures(&w3d->t, w3d->t.list_text);
	ft_clear_image(w3d->mlx, w3d->t);
	ft_clear_mlx(w3d->mlx);
	ft_putstr("mlx :\t\tCLEAR\n");
	while (++i < w3d->height)
		ft_memdel((void **)&w3d->map[i]);
	free(w3d->map);
	ft_putstr("Map tab :\tCLEAR\n");
	ft_memdel((void **)&w3d->len_map);
	ft_memdel((void **)&w3d);
	ft_putstr("Wolf3d :\tCLEAR\n\n");
	exit(0);
}

static void		ft_exit_4(t_wolf3d *w3d)
{
	int		i;

	i = -1;
	while (++i < w3d->height)
		ft_memdel((void **)&w3d->map[i]);
	free(w3d->map);
	ft_putstr("Map tab :\tCLEAR\n");
	ft_memdel((void **)&w3d->len_map);
	ft_memdel((void **)&w3d);
	ft_putstr("Wolf3d :\tCLEAR\n\n");
	exit(0);
}

void			ft_exit_wolf3d(t_wolf3d *w3d, const int exit_code)
{
	if (exit_code == 1)
		ft_exit_1(w3d);
	else if (exit_code == 2)
		ft_exit_2(w3d);
	else if (exit_code == 3)
		ft_exit_3(w3d);
	else if (exit_code == 4)
		ft_exit_4(w3d);
	else if (exit_code == 5)
	{
		ft_putstr("\n\033[31mERROR\033[0m\nBad file\n");
		ft_exit_1(w3d);
	}
}
