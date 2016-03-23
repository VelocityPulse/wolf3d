/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:16:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/23 12:47:30 by cchameyr         ###   ########.fr       */
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
}				t_delta;

typedef struct	s_player
{
	t_pt	pos;
	float	dir;
}				t_player;

typedef struct	s_wolf3d
{
	t_mlx				*mlx;
	t_player			player;
	int					key;
	t_delta				d;
}				t_wolf3d;

void			ft_start(void);
int				press_wolf3d(int keycode, t_wolf3d *w3d);
int				unpress_wolf3d(int keycode, t_wolf3d *w3d);
int				loop_wolf3d(t_wolf3d *w3d);

void			ft_wolf3d(t_wolf3d *w3d);

#endif
