/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:16:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/08 15:47:42 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include <stdbool.h>
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
	double			elipsed_time;
	double			fps;
}				t_delta;

typedef struct	s_raycasting
{
	t_ptd	pos;
	t_ptd	dir;
	t_ptd	plane;
	int		horizon;
}				t_raycasting;

typedef struct	s_wolf3d
{
	t_mlx			*mlx;
	t_ptd			start_pos;
	int				key1;
	int				key2;
	int				key3;
	int				key_sprint;
	double			diff_x;
	int				fps_mode;
	t_delta			d;
	bool			default_map;
	int				def_map[15][20];
	int				**map;
	t_raycasting	r;
}				t_wolf3d;

void			ft_start(char *path);
int				press_wolf3d(int keycode, t_wolf3d *w3d);
int				unpress_wolf3d(int keycode, t_wolf3d *w3d);
int				mouse_wolf3d(int x, int y, t_wolf3d *w3d);
int				loop_wolf3d(t_wolf3d *w3d);

void			get_map1(t_wolf3d *w3d);

void			ft_edit_wolf3d(t_wolf3d *w3d);
void			edit_direction(t_wolf3d *w3d, t_ptd *pos, t_ptd *dir, t_ptd *p);
void			ft_init_rc(t_wolf3d *w3d);
void			ft_reset_wolf_horizon(t_wolf3d *w3d);

void			ft_wolf3d(t_wolf3d *w3d);

#endif
