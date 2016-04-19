/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_get_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:39:55 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/19 12:11:18 by                  ###   ########.fr       */
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

void			get_map_path(t_wolf3d *w3d, const int fd)
{
	char		*line;
	int			nb_line;
	t_lstline	*list;

	line = NULL;
	list = NULL;
	nb_line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		list = ft_add_lstline(list, line);
		nb_line++;
	}
	if (list == NULL)
		ft_exit_wolf3d(w3d, 2);
	if (!ft_check_map(w3d, list, 0, 0))
	{
		ft_lstline_del(list);
		ft_exit_wolf3d(w3d, 1);
	}
	ft_line_to_tab(list, nb_line, w3d);
	ft_lstline_del(list);
	w3d->height = nb_line;
	if (!ft_check_pos_spawn3(w3d))
		ft_exit_wolf3d(w3d, 4);
	ft_complete_case(w3d);
}
