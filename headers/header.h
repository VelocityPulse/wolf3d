/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:16:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/13 14:49:20 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "delta_time.h"
# include "libft.h"
# include "draw.h"
# include "get_next_line.h"
# include "../libmlx/mlx.h"
# include "../libmlx/X.h"

# include "debug.h"

# define W_WIDTH 1080
# define W_HEIGHT 750

typedef struct	s_wolf_line
{
	int		line_start;
	int		line_end;
}				t_wolf_line;

typedef struct	s_raycasting
{
	int		map_x;
	int		map_y;
	double	ray_dirx;
	double	ray_diry;
	double	ray_posx;
	double	ray_posy;
	int		step_x;
	int		step_y;
	int		side;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
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
	double			key_squat;
	double			diff_x;
	int				fps_mode;
	t_delta			d;
	bool			default_map;
	int				**map;
	t_raycasting	r;
}				t_wolf3d;

void			ft_start(char *path);
int				press_wolf3d(int keycode, t_wolf3d *w3d);
int				unpress_wolf3d(int keycode, t_wolf3d *w3d);
int				mouse_wolf3d(int x, int y, t_wolf3d *w3d);
int				loop_wolf3d(t_wolf3d *w3d);

void			get_map1(t_wolf3d *w3d);
void			get_map_path(t_wolf3d *w3d, const int fd);
int				ft_check_map(t_wolf3d *w3d, t_lstline *begin);

void			ft_edit_wolf3d(t_wolf3d *w3d);
void			edit_direction(t_wolf3d *w3d, t_ptd *pos, t_ptd *dir, t_ptd *p);
void			ft_init_rc(t_wolf3d *w3d);
void			ft_reset_wolf_horizon(t_wolf3d *w3d, double squat);

void			ft_wolf3d(t_wolf3d *w3d);

void			ft_exit_wolf3d(t_wolf3d *w3d, const int exit);

#endif
