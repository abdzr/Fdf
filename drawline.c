/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:04:20 by azarzor           #+#    #+#             */
/*   Updated: 2019/02/26 12:39:02 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			key_stroke_2(int key, void *test)
{
	t_env	*env;

	env = (t_env *)test;
	if (key == 78)
		(env->z > 5) ? env->z -= 5 : 0;
	if (key == 49)
	{
		env->clrd = 0xFFFFFF;
		env->clru = 0xFFD700;
	}
	if (key == 8)
	{
		env->clru = 0xFF0000;
		env->clrd = 0x6A5ACD;
	}
	if (key == 9)
	{
		env->clru = 0x7CFC00;
		env->clrd = 0xDAA520;
	}
	(key == 69) ? env->z += 5 : 1;
	(key == 35) ? env->p = 0 : 1;
	(key == 31) ? env->p = 1 : 1;
	(key == 91) ? env->c = env->c - 0.3 : 1;
	(key == 84) ? env->c = env->c + 0.3 : 1;
}

int				key_stroke(int key, void *test)
{
	t_env *env;

	env = (t_env *)test;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	event_3(key, test);
	key_stroke_2(key, test);
	if (key == 65)
	{
		mlx_clear_window(env->mlx_ptr, env->win_ptr);
		mlx_string_put(env->mlx_ptr, env->win_ptr, 100, 100, 0xFFFFFF,
				"Press Arrows to move.");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 100, 120, 0xFFFFFF,
				"Press 4,2,6,8 to rotate.");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 100, 140, 0xFFFFFF,
				"Press C,V, SpaceBar to change colours.");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 100, 160, 0xFFFFFF,
				"Press A and S to change height.");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 100, 180, 0xFFFFFF,
				"Press + and - to zoom.");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 100, 200, 0xFFFFFF,
				"Press O and P to change view.");
	}
	else
		grid(*env);
	return (0);
}

void			linedraw_one(t_env env, t_line p)
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

void			linedraw_two(t_env env, t_line p)
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

void			line(t_env env)
{
	t_line	p;

	p.x = env.xi + 250;
	p.y = env.yi + 250;
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
