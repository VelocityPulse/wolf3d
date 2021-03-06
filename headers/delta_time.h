/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_time.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:52:06 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/24 11:29:27 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DELTA_TIME_H
# define _DELTA_TIME_H

# include <sys/time.h>
# include "libft.h"

typedef struct	s_delta
{
	double			dt;
	struct timeval	t1;
	struct timeval	t2;
	double			elipsed_time;
	double			fps;
}				t_delta;

void			get_delta(t_delta *d, const int fps_mode);
void			start_delta(t_delta *d);
void			end_delta(t_delta *d);

#endif
