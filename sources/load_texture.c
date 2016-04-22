/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 19:17:32 by                   #+#    #+#             */
/*   Updated: 2016/04/22 13:56:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"



static int		ft_load_image(t_mlx *m, t_img *i, char *path)
{
	void	*d;

	i->endian = 0;
	i->p_img = mlx_xpm_file_to_image(m->p_mlx, path, &i->size.x, &i->size.y);
	if (!i->p_img)
	{
		ft_putstr("ERROR\nTexture ");
		ft_putstr(path);
		ft_putstr(" : NOT LOADED\n");
		i->loaded = 0;
		return (1);
	}
	d = mlx_get_data_addr(i->p_img, &i->bpp, &i->width, &i->endian);
	i->octet = i->bpp / 8;
	i->data = d;
	i->max_size = (i->bpp / 8) * i->size.x * i->size.y;
	ft_putstr("Texture ");
	ft_putstr(path);
	ft_putstr(" : LOADED\n");
	i->loaded = 1;
	return (0);
}

static void		ft_list_image(t_texture *t)
{
	t->list_img = (t_img **)ft_memalloc(sizeof(t_img) * 8);
	t->list_img[0] = &t->bluestone;
	t->list_img[1] = &t->colorstone;
	t->list_img[2] = &t->eagle;
	t->list_img[3] = &t->greystone;
	t->list_img[4] = &t->mossy;
	t->list_img[5] = &t->purplestone;
	t->list_img[6] = &t->redbrick;
	t->list_img[7] = &t->wood;
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
		y = t->list_img[i]->size.y;
		t->list_text[i] = (int **)ft_memalloc(sizeof(int *) * y);
		while (y--)
		{
			x = t->list_img[i]->size.x;
			t->list_text[i][y] = (int *)ft_memalloc(sizeof(int) * x);
			while (x--)
				t->list_text[i][y][x] = ft_get_pixel_image(t->list_img[i],
				ft_make_pt(x, y));
		}
	}
}

void			ft_load_textures(t_wolf3d *w3d, t_mlx *mlx, t_texture *t)
{
	int		i;

	i = 0;
	ft_putstr("Loading textures\n");
	i += ft_load_image(mlx, &t->bluestone, "./images/bluestone.xpm");
	i += ft_load_image(mlx, &t->colorstone, "./images/colorstone.xpm");
	i += ft_load_image(mlx, &t->eagle, "./images/eagle.xpm");
	i += ft_load_image(mlx, &t->greystone, "./images/greystone.xpm");
	i += ft_load_image(mlx, &t->mossy, "./images/mossy.xpm");
	i += ft_load_image(mlx, &t->purplestone, "./images/purplestone.xpm");
	i += ft_load_image(mlx, &t->redbrick, "./images/redbrick.xpm");
	i += ft_load_image(mlx, &t->wood, "./images/wood.xpm");
	if (i > 0)
		ft_exit_wolf3d(w3d, 3);
	ft_list_image(&w3d->t);
	ft_list_texture(&w3d->t);
	ft_putstr("All textures loaded\n");
}
