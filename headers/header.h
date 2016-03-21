/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:16:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/21 13:02:01 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "draw.h"
# include "../libmlx/mlx.h"
# include "../libmlx/X.h"

# define W_WIDTH 1080
# define W_HEIGHT 750

typedef struct	s_player
{
	t_pt	pos;
	float	dir;
}				t_player;

typedef struct	s_wolf3d
{
	t_mlx		*mlx;
	t_player	player;
}				t_wolf3d;

void	ft_start(void);

#endif
