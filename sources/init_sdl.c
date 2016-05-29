/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 11:57:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/29 15:15:25 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_env	*ft_init_sdl(t_wolf3d *w3d, int width, int height, char *name)
{
	t_env	*env;

	env = (t_env *)ft_memalloc(sizeof(t_env));
	env->width = width;
	env->height = height;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) ||
	!(env->win = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN)) ||
	!(env->img = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0)))
	{
		ft_putstr("\n\033[31mERROR:\033[0m\n");
		ft_putendl(SDL_GetError());
		ft_destroy_env(env);
		if (w3d->default_map == true)
			ft_exit_wolf3d(w3d, 1);
		ft_exit_wolf3d(w3d, 4);
	}
	return (env);
}
