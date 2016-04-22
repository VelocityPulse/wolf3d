/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 19:17:32 by                   #+#    #+#             */
/*   Updated: 2016/04/22 11:38:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void			ft_clear_textures(t_mlx *mlx, t_texture t)
{
	if (t.bluestone.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.bluestone.p_img);
	if (t.colorstone.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.colorstone.p_img);
	if (t.eagle.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.eagle.p_img);
	if (t.greystone.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.greystone.p_img);
	if (t.mossy.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.mossy.p_img);
	if (t.purplestone.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.purplestone.p_img);
	if (t.redbrick.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.redbrick.p_img);
	if (t.wood.loaded == 1)
		mlx_destroy_image(mlx->p_mlx, t.wood.p_img);
}

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

static void		ft_list_texture(t_texture *t)
{
	t->list = (t_img **)ft_memalloc(sizeof(t_img) * 8);
	t->list[0] = &t->bluestone;
	t->list[1] = &t->colorstone;
	t->list[2] = &t->eagle;
	t->list[3] = &t->greystone;
	t->list[4] = &t->mossy;
	t->list[5] = &t->purplestone;
	t->list[6] = &t->redbrick;
	t->list[7] = &t->wood;
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
	ft_list_texture(t);
	ft_putstr("All textures loaded\n");
}
