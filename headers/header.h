/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:16:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/01 11:45:10 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "libft.h"
# include "draw.h"
# include "../libmlx/mlx.h"
# include "../libmlx/X.h"

# include "debug.h"

# define W_WIDTH 1080
# define W_HEIGHT 750

typedef struct	s_delta
{
	double			dt;
	struct timeval	t1;
	struct timeval	t2;
	double			elipsedTime;
	double			fps;
}				t_delta;

typedef struct	s_raycasting
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}				t_raycasting;

typedef struct	s_map
{
	t_pt	size;
	char	*map;
}				t_map;

typedef struct	s_wolf3d
{
	t_mlx			*mlx;
	int				key;
	t_delta			d;
	t_map			map;
	t_raycasting	r;
}				t_wolf3d;

void			ft_start(void);
int				press_wolf3d(int keycode, t_wolf3d *w3d);
int				unpress_wolf3d(int keycode, t_wolf3d *w3d);
int				loop_wolf3d(t_wolf3d *w3d);

void			get_map1(t_map *mapi);

void			ft_edit_wolf3d(t_wolf3d *w3d);
void			ft_init_rc(t_raycasting *r);

void			ft_wolf3d(t_wolf3d *w3d);

#endif
