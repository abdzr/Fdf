/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:04:20 by azarzor           #+#    #+#             */
/*   Updated: 2019/01/31 17:19:37 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			key_stroke_2(int key, void *test)
{
	t_env	*env;

	env = (t_env *)test;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	if (key == 7)
	{
		env->z -= 5;
		if (env->z < 0)
			env->z = 30;
	}
	(key == 49) ? env->color = 0xFFFFFF : 1;
	grid(*env);
}

int				key_stroke(int key, void *test)
{
	t_env *env;

	env = (t_env *)test;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	(key == 53) ? exit(0) : 1;
	(key == 126) ? env->u = env->u - 5 : 1;
	(key == 125) ? env->u = env->u + 5 : 1;
	(key == 124) ? env->s = env->s + 5 : 1;
	(key == 123) ? env->s = env->s - 5 : 1;
	(key == 15) ? env->a = env->a + 0.3 : 1;
	(key == 14) ? env->sc = env->sc + 1 : 1;
	(key == 13) ? env->sc = env->sc - 1 : 1;
	(key == 17) ? env->a = env->a - 0.3 : 1;
	(key == 0) ? env->c = env->c - 0.3 : 1;
	(key == 1) ? env->c = env->c + 0.3 : 1;
	(key == 6) ? env->z += 5 : 1;
	(key == 8) ? env->color = 0xFF0000 : 1;
	(key == 9) ? env->color = 0x00FF00 : 1;
	(key == 11) ? env->color = 0x0000FF : 1;
	(key == 35) ? env->p = 0 : 1;
	(key == 31) ? env->p = 1 : 1;
	key_stroke_2(key, test);
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
