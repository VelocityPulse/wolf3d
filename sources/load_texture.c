/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:08:49 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/22 14:32:14 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static int		ft_get_pixel_image(SDL_Surface *img, int x, int y)
{
	if (x < 0 || y < 0 || x > img->w || y > img->h)
		return (0);
	return (*(unsigned int *)(unsigned long)(img->pixels +
				x * img->format->BytesPerPixel + y * img->pitch));
}

static int		ft_load_bmp(SDL_Surface **surface, char *path)
{
	if (!(*surface = SDL_LoadBMP(path)))
	{
		ft_putstr("Texture ");
		ft_putstr(path);
		ft_putstr(" : NOT LOADED !!\n");
		return (1);
	}
	ft_putstr("Texture ");
	ft_putstr(path);
	ft_putstr(" : LOADED\n");
	return (0);
}

static void		ft_list_image(t_texture *t)
{
	t->list_img = (SDL_Surface **)ft_memalloc(sizeof(SDL_Surface *) * 8);
	t->list_img[0] = t->bluestone;
	t->list_img[1] = t->colorstone;
	t->list_img[2] = t->eagle;
	t->list_img[3] = t->greystone;
	t->list_img[4] = t->mossy;
	t->list_img[5] = t->purplestone;
	t->list_img[6] = t->redbrick;
	t->list_img[7] = t->wood;
	ft_putstr("List texture image : DONE\n");
}

static void		ft_list_texture(t_texture *t)
{
	int		i;
	int		x;
	int		y;

	t->list_text = (int ***)ft_memalloc(sizeof(int **) * 8);
	i = -1;
	while (++i <= 7)
	{
		x = t->list_img[i]->w;
		t->list_text[i] = (int **)ft_memalloc(sizeof(int *) * x);
		while (x--)
		{
			y = t->list_img[i]->h;
			t->list_text[i][x] = (int *)ft_memalloc(sizeof(int) * y);
			while (y--)
				t->list_text[i][x][y] = ft_get_pixel_image(t->list_img[i],
						x, y);
		}
	}
	ft_putstr("List texture tab : DONE\n");
}

void			ft_load_textures(t_wolf3d *w3d, t_texture *t)
{
	int		i;

	i = 0;
	ft_putstr("Loading textures...\n");
	i += ft_load_bmp(&t->bluestone, "images/bluestone.bmp");
	i += ft_load_bmp(&t->colorstone, "images/colorstone.bmp");
	i += ft_load_bmp(&t->eagle, "images/eagle.bmp");
	i += ft_load_bmp(&t->greystone, "images/greystones.bmp");
	i += ft_load_bmp(&t->mossy, "images/mossy.bmp");
	i += ft_load_bmp(&t->purplestone, "images/purplestone.bmp");
	i += ft_load_bmp(&t->redbrick, "images/redbrick.bmp");
	i += ft_load_bmp(&t->wood, "images/wood.bmp");
	if (i > 0)
		ft_exit_wolf3d(w3d, 2);
	ft_list_image(t);
	ft_list_texture(t);
	ft_putstr("All textures loaded\n\n");
}
