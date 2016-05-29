/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:16:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/29 15:23:18 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "../SDL2-2.0.4/include/SDL.h"
# include "delta_time.h"
# include "libft.h"
# include "get_next_line.h"

# include "debug.h"

# define W_WIDTH 1080
# define W_HEIGHT 750

# define _NORTH_ 4
# define _EST_ 3
# define _SOUTH_ 2
# define _WEST_ 1

typedef struct	s_env
{
	SDL_Window		*win;
	SDL_Surface		*img;
	SDL_Event		events;
	int				width;
	int				height;
}				t_env;

typedef struct	s_texture
{
	SDL_Surface		*bluestone;
	SDL_Surface		*colorstone;
	SDL_Surface		*eagle;
	SDL_Surface		*greystone;
	SDL_Surface		*mossy;
	SDL_Surface		*purplestone;
	SDL_Surface		*redbrick;
	SDL_Surface		*wood;
	int				***list_text;
	SDL_Surface		**list_img;
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
	int				tex_val;
	char			cardinal;
	int				*key_squat;
}				t_trace_var;

typedef struct	s_wolf3d
{
	t_env			*env;
	t_ptd			start_pos;
	bool			fps_mode;
	t_delta			d;
	bool			default_map;
	int				*len_map;
	int				**map;
	int				height;
	int				scanvalue[285];
	t_trace_var		var;
	t_texture		t;
	t_raycasting	r;
	double			diff_x;
}				t_wolf3d;

t_env			*ft_init_sdl(t_wolf3d *w3d, int width, int height, char *name);
void			ft_destroy_env(t_env *env);

void			ft_start(char *path);

void			get_map1(t_wolf3d *w3d);
void			get_map_path(t_wolf3d *w3d, const int fd, int nb_l, char *line);
int				ft_check_map(t_wolf3d *w3d, t_lstline *l, int max_x, int s);
void			ft_complete_case(t_wolf3d *w3d);
void			ft_display_map(t_wolf3d *w3d);

int				ft_error(int nb_spawn, int y, int max_x);
int				ft_error_line(t_pt p, int code);
int				ft_check_pos_spawn(t_wolf3d *w3d, int *max_x, t_pt p, int spwn);
int				ft_check_pos_spawn3(t_wolf3d *w3d);

void			ft_load_textures(t_wolf3d *w3d, t_texture *t);
void			ft_clear_list_textures(t_texture *t, int ***list_text);
void			ft_clear_image(t_texture t);

void			ft_trace(t_wolf3d *w3d, int line_start, int line_end, int x);

void			ft_edit_wolf3d(t_wolf3d *w3d);
void			edit_direction(t_wolf3d *w3d, t_ptd *dir, t_ptd *p);
void			ft_init_rc(t_wolf3d *w3d);

void			ft_run(t_wolf3d *w3d);
void			ft_wolf3d(t_wolf3d *w3d);

int				ft_trace_top(t_trace_var *var, int x, int l_start, int octet);
void			ft_trace_bot(t_trace_var *var, int pos, int line_start);
void			ft_trace_monocolor(t_wolf3d *w3d, int lstart, int lend, int x);
void			ft_exit_wolf3d(t_wolf3d *w3d, const int exit);

#endif
