/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:26:30 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/28 10:49:01 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_run(t_wolf3d *w3d)
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
				w3d->scanvalue[events.key.keysym.scancode] = 1;
			else if (events.type == SDL_KEYDOWN)
				w3d->scanvalue[events.key.keysym.scancode] = 0;
			
		}
		ft_wolf3d(w3d);
		SDL_BlitSurface(env->img, NULL, SDL_GetWindowSurface(env->win), NULL);
		SDL_UpdateWindowSurface(env->win);
		end_delta(&w3d->d);
		get_delta(&w3d->d, w3d->scanvalue[SDL_SCANCODE_F]);
	}
}
