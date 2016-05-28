/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:26:30 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/28 12:25:36 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_help_key(t_wolf3d *w3d)
{
	if (w3d->fps_mode == 1 && w3d->scanvalue[SDL_SCANCODE_F] == 1)
		w3d->fps_mode = 0;
	else if (w3d->fps_mode == 0 && w3d->scanvalue[SDL_SCANCODE_F] == 1)
		w3d->fps_mode = 1;
}

void			ft_run(t_wolf3d *w3d)
{
	SDL_Event		events;
	t_env			*env;

	env = w3d->env;
	while (1)
	{
		start_delta(&w3d->d);
		while (SDL_PollEvent(&events))
		{
			if (events.type == SDL_KEYDOWN)
			{
				w3d->scanvalue[events.key.keysym.scancode] = 1;
				ft_help_key(w3d);
			}
			else if (events.type == SDL_KEYUP)
				w3d->scanvalue[events.key.keysym.scancode] = 0;
			if (events.type == SDL_QUIT ||
					w3d->scanvalue[SDL_SCANCODE_ESCAPE] == 1)
				ft_exit_wolf3d(w3d, 3);
		}
		ft_wolf3d(w3d);
		SDL_BlitSurface(env->img, NULL, SDL_GetWindowSurface(env->win), NULL);
		SDL_UpdateWindowSurface(env->win);
		end_delta(&w3d->d);
		get_delta(&w3d->d, w3d->fps_mode);
	}
}
