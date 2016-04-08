/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:16:22 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/08 14:59:31 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_start(NULL);
	if (argc == 2)
		ft_start(argv[1]);
	else if (argc > 2)
		ft_putstr("Too much files\n");
	return (0);
}
