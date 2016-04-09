/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_get_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:39:55 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/09 12:59:55 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft

void			get_map_path(t_wolf3d *w3d, const int fd)
{
	char		*line;
	t_lstline	*list;

	line = NULL;
	list = NULL;
	w3d->nb_line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		//		if (ft_check_line(line) == 0)
		if (0)
		{
			ft_lstline_del(list);
			ft_exit_wolf3d(w3d, 1);
		}
		list = ft_add_lstline(list, line);
		w3d->nb_line++;
	}
	ft_line_to_tab(list, w3d->nb_line, w3d);
	ft_lstline_del(list);
}
