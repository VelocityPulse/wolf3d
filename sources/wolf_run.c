/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:26:30 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/29 15:38:18 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_help_key(t_wolf3d *w3d)
{
	if (w3d->fps_mode == 1 && w3d->scanvalue[SDL_SCANCODE_F] == 1)
		w3d->fps_mode = 0;
	else if (w3d->fps_mode == 0 && w3d->scanvalue[SDL_SCANCODE_F] == 1)
		w3d->fps_mode = 1;
	if (w3d->scanvalue[SDL_SCANCODE_RCTRL] == 1)
		SDL_SetRelativeMouseMode(SDL_DISABLE);
}

static void		ft_mouse_motion(t_wolf3d *w3d, SDL_MouseMotionEvent *mevent)
{
	int				x;

	x = mevent->xrel;
	w3d->diff_x = x / 5;
	if (w3d->diff_x < 0.0f)
	{
		w3d->diff_x = -w3d->diff_x;
		w3d->scanvalue[SDL_SCANCODE_LEFT] = 1;
		edit_direction(w3d, &w3d->r.dir, &w3d->r.plane);
		w3d->scanvalue[SDL_SCANCODE_LEFT] = 0;
	}
	else if (w3d->diff_x > 0.0f)
	{
		w3d->scanvalue[SDL_SCANCODE_RIGHT] = 1;
		edit_direction(w3d, &w3d->r.dir, &w3d->r.plane);
		w3d->scanvalue[SDL_SCANCODE_RIGHT] = 0;
	}
	w3d->diff_x = 1;
}

static void		ft_mouse_button(t_wolf3d *w3d, SDL_MouseButtonEvent *bevent)
{
	if ((bevent->button == SDL_BUTTON_LEFT) &&
	((bevent->x > 0 && bevent->y > 0) &&
	(bevent->x < W_WIDTH && bevent->y < W_HEIGHT)))
		SDL_SetRelativeMouseMode(SDL_ENABLE);
	(void)w3d;
}

static void		ft_event(t_wolf3d *w3d)
{
	static SDL_Event	events;
	int					mouse_mode;

	mouse_mode = SDL_GetRelativeMouseMode();
	while (SDL_PollEvent(&events))
	{
		if (events.type == SDL_KEYDOWN && mouse_mode == SDL_TRUE)
		{
			w3d->scanvalue[events.key.keysym.scancode] = 1;
			ft_help_key(w3d);
		}
		if (events.type == SDL_KEYUP)
			w3d->scanvalue[events.key.keysym.scancode] = 0;
		if (events.type == SDL_MOUSEMOTION && mouse_mode == SDL_TRUE)
			ft_mouse_motion(w3d, &events.motion);
		if (events.type == SDL_QUIT ||
		w3d->scanvalue[SDL_SCANCODE_ESCAPE] == 1)
			ft_exit_wolf3d(w3d, 3);
		if (events.type == SDL_MOUSEBUTTONDOWN)
			ft_mouse_button(w3d, &events.button);
	}
}

void			ft_run(t_wolf3d *w3d)
{
	t_env			*env;

	env = w3d->env;
	SDL_SetRelativeMouseMode(SDL_DISABLE);
	while (1)
	{
		start_delta(&w3d->d);
		ft_event(w3d);
		ft_wolf3d(w3d);
		SDL_BlitSurface(env->img, NULL, SDL_GetWindowSurface(env->win), NULL);
		SDL_UpdateWindowSurface(env->win);
		end_delta(&w3d->d);
		get_delta(&w3d->d, w3d->fps_mode);
	}
}
