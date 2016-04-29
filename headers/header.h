/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:16:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/29 14:48:06 by                  ###   ########.fr       */
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

typedef struct	s_texture
{
	t_img	bluestone;
	t_img	colorstone;
	t_img	eagle;
	t_img	greystone;
	t_img	mossy;
	t_img	purplestone;
	t_img	redbrick;
	t_img	wood;
	int		***list_text;
	t_img	**list_img;
}				t_texture;

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
	double	perp_wall_dist;
	int		side;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	t_ptd	pos;
	t_ptd	dir;
	t_ptd	plane;
	int		horizon;
	int		val;
	int		x;
}				t_raycasting;

typedef struct	s_trace_var
{
	t_raycasting	*r;
	t_texture		*t;
	void			*data;
	int				width;
	int				octet;
	int				max_size;
	int				line_start;
	int				line_end;
	int				line_height;
	int				size_y;
	double			*key_squat;
	int				tex_val;
	int				mlx_height;
}				t_trace_var;

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
	int				*len_map;
	int				**map;
	int				height;
	t_trace_var		var;
	t_texture		t;
	t_raycasting	r;
}				t_wolf3d;

void			ft_start(char *path);
int				press_wolf3d(int keycode, t_wolf3d *w3d);
int				unpress_wolf3d(int keycode, t_wolf3d *w3d);
int				mouse_wolf3d(int x, int y, t_wolf3d *w3d);
int				loop_wolf3d(t_wolf3d *w3d);

void			get_map1(t_wolf3d *w3d);
void			get_map_path(t_wolf3d *w3d, const int fd);
int				ft_check_map(t_wolf3d *w3d, t_lstline *l, int max_x, int s);
void			ft_complete_case(t_wolf3d *w3d);
void			ft_display_map(t_wolf3d *w3d);

int				ft_error(int nb_spawn, int y, int max_x);
int				ft_error_line(t_pt p, int code);
int				ft_check_pos_spawn(t_wolf3d *w3d, int *max_x, t_pt p, int spwn);
int				ft_check_pos_spawn3(t_wolf3d *w3d);

void			ft_load_textures(t_wolf3d *w3d, t_mlx *mlx, t_texture *t);
void			ft_clear_list_textures(t_texture *t, int ***list_text);
void			ft_clear_image(t_mlx *mlx, t_texture t);

void			ft_trace(t_wolf3d *w3d, int line_start, int line_end, int x);

void			ft_edit_wolf3d(t_wolf3d *w3d);
void			edit_direction(t_wolf3d *w3d, t_ptd *dir, t_ptd *p);
void			ft_init_rc(t_wolf3d *w3d);
void			ft_reset_wolf_horizon(t_wolf3d *w3d, double squat);

void			ft_wolf3d(t_wolf3d *w3d);

void			ft_exit_wolf3d(t_wolf3d *w3d, const int exit);

#endif
