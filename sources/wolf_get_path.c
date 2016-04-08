/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_get_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:39:55 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/08 23:37:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_get_map_path(t_wolf3d *w3d, int fd)
{
	char		*line;
	t_lstline	*list;

	line = NULL;
	list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_check_line(line) == 0)
		{
			ft_lstline_del(list);
			
		}
	}
}
