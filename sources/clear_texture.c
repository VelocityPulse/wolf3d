/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:22:52 by                   #+#    #+#             */
/*   Updated: 2016/04/22 12:34:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void			ft_clear_image(t_mlx *mlx, t_texture t)
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
/*
void			ft_clear_list_textures(t_texture *t, int ***list_text)
{
	int		i;
	int		y;

	i = -1;
	while (++i <= 7)
	{
		y = t->list_img[i]->size.y;
		while (y--)
			ft_memdel((void **)&list_text[i][y]);
		ft_memdel((void **)list_text[i]);
	}
	free(list_text);
}
*/
