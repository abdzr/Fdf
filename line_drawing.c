/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:26:57 by azarzor           #+#    #+#             */
/*   Updated: 2019/01/31 16:46:56 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <math.h>

void		key_stroke_2(int key, void *test)
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

int			key_stroke(int key, void *test)
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

void		calculs(t_env env, t_point ta[env.i][env.j])
{
	int		i;
	int		j;

	i = 0;
	while (i < env.i)
	{
		j = 0;
		while (j < env.j)
		{
			if (env.p == 0)
			{
				ta[i][j].y = ((j - env.hx) + (i - env.hy)) * sin(env.c) *
					env.z + env.u - (env.tab[i][j] * env.sc);
				ta[i][j].x = ((j - env.hx) - (i - env.hy)) * cos(env.a) *
					env.z + env.s;
			}
			else
			{
				ta[i][j].x = j * env.z + 0.5 * env.tab[i][j] * env.sc + env.s;
				ta[i][j].y = i * env.z + (0.5 / 2) * env.tab[i][j] * env.sc + env.u;
			}
			j++;
		}
		i++;
	}
}

void		maindraw(t_env env, t_point ta[env.i][env.j], int *i, int *j)
{
	*i = 0;
	while (*i < env.i)
	{
		*j = 0;
		while (*j < env.j)
		{
			env.xi = ta[*i][*j].x;
			env.yi = ta[*i][*j].y;
			if (*j != env.j - 1)
			{
				env.xf = ta[*i][*j + 1].x;
				env.yf = ta[*i][*j + 1].y;
				line(env);
			}
			if (*i != env.i - 1)
			{
				env.xf = ta[*i + 1][*j].x;
				env.yf = ta[*i + 1][*j].y;
				line(env);
			}
			(*j)++;
		}
		(*i)++;
	}
}

void		grid(t_env env)
{
	t_point	ta[env.i][env.j];
	int		i;
	int		j;

	calculs(env, ta);
	maindraw(env, ta, &i, &j);
}
