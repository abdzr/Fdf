/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:26:57 by azarzor           #+#    #+#             */
/*   Updated: 2019/02/26 12:39:04 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <math.h>

void		event_3(int key, void *test)
{
	t_env *env;

	env = (t_env *)test;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	(key == 53) ? exit(0) : 1;
	(key == 126) ? env->u = env->u - 5 : 1;
	(key == 125) ? env->u = env->u + 5 : 1;
	(key == 124) ? env->s = env->s + 5 : 1;
	(key == 123) ? env->s = env->s - 5 : 1;
	(key == 88) ? env->a = env->a + 0.3 : 1;
	(key == 86) ? env->a = env->a - 0.3 : 1;
	(key == 0) ? env->sc = env->sc + 1 : 1;
	(key == 1) ? env->sc = env->sc - 1 : 1;
}

void		calculs(t_env env, t_point **ta)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env.i)
	{
		j = -1;
		while (++j < env.j)
		{
			(env.p == 0) ? ta[i][j].y = ((j - env.hx) + (i - env.hy)) *
				sin(env.c) * env.z + env.u - (env.tab[i][j] * env.sc) : 0;
			(env.p == 0) ? ta[i][j].x = ((j - env.hx) - (i - env.hy)) *
				cos(env.a) * env.z + env.s : 0;
			(env.p != 0) ? ta[i][j].x = (j - env.hx) * env.z +
				0.5 * env.tab[i][j] * env.sc + env.s : 0;
			(env.p != 0) ? ta[i][j].y = (i - env.hy) * env.z + (0.5 / 2) *
				env.tab[i][j] * env.sc + env.u : 0;
			ta[i][j].z = env.tab[i][j];
		}
	}
}

void		maindraw(t_env env, t_point **ta, int *i, int *j)
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
				env.color = (ta[*i][*j].z != 0) ? env.clru : env.clrd;
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

t_point		**taballoc(t_env env)
{
	int		i;
	t_point	**ta;

	ta = (t_point **)malloc(sizeof(t_point *) * env.i);
	i = 0;
	while (i < env.i)
	{
		ta[i] = (t_point*)malloc(sizeof(t_point) * env.j);
		i++;
	}
	return (ta);
}

void		grid(t_env env)
{
	t_point	**ta;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ta = taballoc(env);
	calculs(env, ta);
	maindraw(env, ta, &i, &j);
}
