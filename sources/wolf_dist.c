/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:29:29 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/26 17:05:52 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static float	ft_calc_dist(t_pt p, t_pt pos, float d)
{
	t_pt3df		tmp;

	if (p.y < pos.y)
		tmp.y = pos.y - p.y;
	else
		tmp.y = p.y - pos.y;
	if (p.x < pos.x)
		tmp.x = pos.x - p.x;
	else
		tmp.x = p.x - pos.x;
	return (sqrtf(tmp.x * tmp.x + tmp.y * tmp.y));
}

static t_wall	ft_digit_diff_analyser_x(t_pt pos, t_map m, t_pt var, float d)
{
	float		a;
	float		err;
	t_pt		p;
	t_wall		w;

	a = d / 45;
	err = 0;
	p = pos;
	printf("dda x\ndeg : %f\na : %f\n", d, a);
	while (m.map[p.y * m.size.x + p.x] == 0 &&
			(p.y < m.size.y) && (p.x < m.size.x))
	{
		err += a;
		if (err > 0.5)
		{
			err -= 1;
			p.y += var.y;
			printf("impact : x %d ; y %d\n", p.x, p.y);
		}
		p.x += var.x;
		printf("impact : x %d ; y %d\n", p.x, p.y);
	}
	printf("impact : x %d ; y %d\n", p.x, p.y);
	w.dist = ft_calc_dist(p, pos, d);
	w.code = m.map[p.y * m.size.x + p.x];
	printf("dist : %f\ncode : %d\n\n", w.dist, w.code);
	return (w);
}

static t_wall	ft_digit_diff_analyser_y(t_pt pos, t_map m, t_pt var, float d)
{
	float		a;
	float		err;
	t_pt		p;
	t_wall		w;

	a = d / 45;
	err = 0;
	p = pos;
	printf("dda y\ndeg : %f\na : %f\n", d, a);
	while (m.map[(p.y - 1) * m.size.x + (p.x - 1)] == 0 /*&&
			(p.y < m.size.y) && (p.x < m.size.x)*/)
	{
		err += a;
		if (err > 0.5)
		{
			err -= 1;
			p.x += var.x;
			printf("impact : x %d ; y %d\n", p.x, p.y);
		}
		p.y += var.y;
		printf("impact : x %d ; y %d\n", p.x, p.y);
	}
	printf("impact : x %d ; y %d\n", p.x, p.y);
	w.dist = ft_calc_dist(p, pos, d);
	w.code = m.map[(p.y - 1) * m.size.x + (p.x - 1)];
	printf("dist : %f\ncode : %d\n\n", w.dist, w.code);
	return (w);
}

t_wall			ft_dist(t_map map, t_pt pos, float deg)
{
	t_wall		w;
	t_pt		var;

	if (deg >= 0 && deg <= 45)
		w = ft_digit_diff_analyser_y(pos, map, ft_make_pt(1, -1), deg);
	else if  (deg > 45 && deg <= 90)
		w = ft_digit_diff_analyser_x(pos, map, ft_make_pt(1, -1), 45 - (deg - 45));
	else if (deg > 90 && deg < 135)
		w = ft_digit_diff_analyser_x(pos, map, ft_make_pt(1, 1), deg - 90);
	else if (deg >= 135 && deg < 180)
		w = ft_digit_diff_analyser_y(pos, map, ft_make_pt(1, 1), 45 - (deg - 135));
	return (w);
}
