/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_pt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:44:44 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 13:44:50 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pt	ft_make_pt(int x, int y)
{
	t_pt	pt;

	pt.x = x;
	pt.y = y;
	return (pt);
}
