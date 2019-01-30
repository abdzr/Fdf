/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:26:57 by azarzor           #+#    #+#             */
/*   Updated: 2019/01/30 15:29:30 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <math.h>

int key_stroke(int key, void *test)
{
    t_env *env = NULL;

    env = (t_env *)test;
    mlx_clear_window(env->mlx_ptr, env->win_ptr);
    if (key == 53)
        exit(0);
    if (key == 126)
        env->u = env->u - 5;
    if (key == 125)
        env->u = env->u + 5;
    if (key == 124)
        env->s = env->s + 5;
    if (key == 123)
        env->s = env->s - 5;
    if (key == 15)
        env->ang = env->ang + 0.3;
    if (key == 14)
        env->sc = env->sc + 2;
    if (key == 13)
        env->sc = env->sc - 2;
    if (key == 17)
        env->ang = env->ang - 0.3;
    if (key == 0)
        env->crm = env->crm - 0.3;
    if (key == 1)
        env->crm = env->crm + 0.3;
    if (key == 6)
        env->z += 5;
    if (key == 7)
        {
            env->z -= 5;
            if (env->z < 0)
                env->z = 30;
        }
    grid(*env);
    return (0);
}

void line(t_env env)
{
    t_line p;
    int j;

    p.x = env.xi + 500;
    p.y = env.yi + 500;
    p.dx = env.xf - env.xi;
    p.dy = env.yf - env.yi;
    p.xinc = (p.dx > 0) ? 1 : -1;
    p.yinc = (p.dy > 0) ? 1 : -1;
    p.dx = abs(p.dx);
    p.dy = abs(p.dy);
    mlx_pixel_put(env.mlx_ptr, env.win_ptr, p.x, p.y, 0xFFFFF);
    if (p.dx > p.dy)
    {
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
            mlx_pixel_put(env.mlx_ptr, env.win_ptr, p.x, p.y, 0xFFFFF);
            j++;
        }
    }
    else
    {
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
            mlx_pixel_put(env.mlx_ptr, env.win_ptr, p.x, p.y, 0xFFFFF);
            j++;
        }
    }
}

void grid(t_env env)
{
    t_point T[env.i][env.j];
    int i;
    int j;

    {
        i = 0;
        while (i < env.i)
        {
            j = 0;
            while (j < env.j)
            {
                T[i][j].x = ((j - env.hx) - (i - env.hy)) * cos(0.523599 + env.ang) * env.z + env.s;
                T[i][j].y = ((j - env.hx) + (i - env.hy)) * sin(0.523599 + env.crm) * env.z + env.u - (env.tab[i][j] * env.sc);
                j++;
            }
            i++;
        }
    }
    i = 0;
    while (i < env.i)
    {
        j = 0;
        while (j < env.j)
        {
            env.xi = T[i][j].x;
            env.yi = T[i][j].y;
            env.xf = T[i][j + 1].x;
            env.yf = T[i][j + 1].y;
            if (j != env.j - 1)
                line(env);
            env.xf = T[i + 1][j].x;
            env.yf = T[i + 1][j].y;
            if (i != env.i - 1)
                line(env);
            j++;
        }
        i++;
    }
}