/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_get_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:55:18 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/03 15:10:45 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_line_to_tab(t_lstline *list, int nb_line, t_wolf3d *w3d)
{
	char	**str;
	int		y;
	int		x;

	w3d->map = (int **)ft_memalloc(sizeof(int *) * (nb_line + 1));
	w3d->len_map = (int *)ft_memalloc(sizeof(int) * nb_line + 1);
	y = -1;
	while (++y < nb_line)
	{
		str = ft_strsplit(list->line, ' ');
		w3d->len_map[y] = ft_memlen((void **)str);
		w3d->map[y] = (int *)ft_memalloc(sizeof(int) * (w3d->len_map[y] + 1));
		x = -1;
		while (str[++x])
			w3d->map[y][x] = ft_atoi(str[x]);
		while (x--)
			ft_memdel((void **)&str[x]);
		ft_memdel((void **)str);
		list = list->next;
	}
}

static void		ft_exit_list(t_wolf3d *w3d, t_lstline *list, int nb_line)
{
	ft_putstr("ERROR:\nLINE : ");
	ft_putnbr(nb_line + 1);
	ft_putstr(" is empty\n");
	ft_lstline_del(list);
	ft_exit_wolf3d(w3d, 1);
}

void			get_map_path(t_wolf3d *w3d, const int fd, int nb_l, char *line)
{
	t_lstline	*list;

	list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '\0')
			ft_exit_list(w3d, list, nb_l);
		list = ft_add_lstline(list, line);
		nb_l++;
	}
	if (list == NULL)
		ft_exit_wolf3d(w3d, 5);
	if (!ft_check_map(w3d, list, 0, 0))
	{
		ft_lstline_del(list);
		ft_exit_wolf3d(w3d, 1);
	}
	ft_line_to_tab(list, nb_l, w3d);
	ft_lstline_del(list);
	w3d->height = nb_l;
	if (!ft_check_pos_spawn3(w3d))
		ft_exit_wolf3d(w3d, 4);
	ft_complete_case(w3d);
}
