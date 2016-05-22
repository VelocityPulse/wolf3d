/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:59:40 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/22 12:50:49 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void			ft_clear_image(t_texture t)
{
	SDL_FreeSurface(t.bluestone);
	SDL_FreeSurface(t.colorstone);
	SDL_FreeSurface(t.eagle);
	SDL_FreeSurface(t.greystone);
	SDL_FreeSurface(t.mossy);
	SDL_FreeSurface(t.purplestone);
	SDL_FreeSurface(t.redbrick);
	SDL_FreeSurface(t.wood);
	ft_putstr("Texture image :\tCLEAR\n");
}

void			ft_clear_list_textures(t_texture *t, int ***list_text)
{
	int		i;
	int		y;

	i = -1;
	while (++i <= 7)
	{
		y = (*t->list_img[i])->clip_rect.h;
		while (y--)
			ft_memdel((void **)&list_text[i][y]);
		ft_memdel((void **)list_text[i]);
	}
	free(list_text);
	ft_putstr("Texture tab :\tCLEAR\n");
}
