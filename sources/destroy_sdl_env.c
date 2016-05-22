/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sdl_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 12:51:56 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/22 12:53:56 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_destroy_env(t_env *env)
{
	SDL_FreeSurface(env->img);
	SDL_DestroyWindow(env->win);
	SDL_Quit();
	ft_memdel((void **)&env);
}
