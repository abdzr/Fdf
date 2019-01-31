/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:04:20 by azarzor           #+#    #+#             */
/*   Updated: 2019/01/31 16:52:23 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	linedraw_one(t_env env, t_line p)
{
	int		j;

	p.cumul = p.dx / 2;
	j = 1;
	while (j <= p.dx)
	{
		p.x += (p.xinc);
		p.cumul += (p.dy);
		if (p.cumul >= p.dx)
		{
			p.cumul -= (p.dx);
			p.y += (p.yinc);
		}
		mlx_pixel_put(env.mlx_ptr, env.win_ptr, p.x, p.y, env.color);
		j++;
	}
}

void	linedraw_two(t_env env, t_line p)
{
	int		j;

	p.cumul = p.dy / 2;
	j = 1;
	while (j <= p.dy)
	{
		p.y += (p.yinc);
		p.cumul += (p.dx);
		if (p.cumul >= p.dy)
		{
			p.cumul -= (p.dy);
			p.x += (p.xinc);
		}
		mlx_pixel_put(env.mlx_ptr, env.win_ptr, p.x, p.y, env.color);
		j++;
	}
}

void	line(t_env env)
{
	t_line	p;

	p.x = env.xi + 100;
	p.y = env.yi + 100;
	p.dx = env.xf - env.xi;
	p.dy = env.yf - env.yi;
	p.xinc = (p.dx > 0) ? 1 : -1;
	p.yinc = (p.dy > 0) ? 1 : -1;
	p.dx = abs(p.dx);
	p.dy = abs(p.dy);
	mlx_pixel_put(env.mlx_ptr, env.win_ptr, p.x, p.y, env.color);
	if (p.dx > p.dy)
		linedraw_one(env, p);
	else
		linedraw_two(env, p);
}
