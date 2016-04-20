/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 19:17:32 by                   #+#    #+#             */
/*   Updated: 2016/04/20 11:54:30 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void			ft_clear_textures(t_mlx *mlx, t_texture t)
{
	mlx_destroy_image(mlx->p_mlx, t.bluestone.p_img);
	mlx_destroy_image(mlx->p_mlx, t.colorstone.p_img);
	mlx_destroy_image(mlx->p_mlx, t.eagle.p_img);
	mlx_destroy_image(mlx->p_mlx, t.greystone.p_img);
	mlx_destroy_image(mlx->p_mlx, t.mossy.p_img);
	mlx_destroy_image(mlx->p_mlx, t.purplestone.p_img);
	mlx_destroy_image(mlx->p_mlx, t.redbrick.p_img);
	mlx_destroy_image(mlx->p_mlx, t.wood.p_img);
}

static void		ft_load_image(t_mlx *m, t_img *i, char *path)
{
	void	*d;

	i->endian = 0;
	i->p_img = mlx_xpm_file_to_image(m->p_mlx, path, &i->size.x, &i->size.y);
	if (!i->p_img)
		return ;
	d = mlx_get_data_addr(i->p_img, &i->bpp, &i->width, &i->endian);
	i->data = d;
	i->max_size = (i->bpp / 8) * i->width * i->size.y;
}

void			ft_load_textures(t_mlx *mlx, t_texture *t)
{
	printf("mlx->width : %d\nimg->width : %d\n", mlx->width, mlx->mlx_img->width);

	ft_load_image(mlx, &t->bluestone, "./images/bluestone.xpm");
	ft_load_image(mlx, &t->colorstone, "./images/colorstone.xpm");
	ft_load_image(mlx, &t->eagle, "./images/eagle.xpm");
	ft_load_image(mlx, &t->greystone, "./images/greystone.xpm");
	ft_load_image(mlx, &t->mossy, "./images/mossy.xpm");
	ft_load_image(mlx, &t->purplestone, "./images/purplestone.xpm");
	ft_load_image(mlx, &t->redbrick, "./images/redbrick.xpm");
	ft_load_image(mlx, &t->wood, "./images/wood.xpm");
}
