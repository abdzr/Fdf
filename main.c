/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:56:03 by azarzor           #+#    #+#             */
/*   Updated: 2019/01/31 18:01:56 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdio.h>

int			get_x(int fd, char *line)
{
	int i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
		line = NULL;
	}
	return (i);
}

int			get_y(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		initialisation(t_env *env)
{
	env->a = 0.523599;
	env->c = 0.523599;
	env->hy = env->i / 2;
	env->hx = env->j / 2;
	env->u = 0;
	env->z = 20;
	env->color = 0xFFFFFF;
	env->p = 0;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->i * 60,
			env->j * 30, "FDF");
	grid(*env);
	mlx_key_hook(env->win_ptr, &key_stroke, env);
	mlx_loop(env->mlx_ptr);
}

int			main(int argc, char **argv)
{
	int			fd;
	char		*liine;
	t_env		env;
	char		**str;
	int			x;

	liine = NULL;
	(argc != 2) ? ft_putstr("Error\n") : 1;
	fd = open(argv[1], O_RDONLY);
	x = get_x(fd, liine);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	env.tab = (int **)malloc(sizeof(int *) * (x + 1));
	env.i = 0;
	while (get_next_line(fd, &liine) > 0)
	{
		str = ft_strsplit(liine, ' ');
		free(liine);
		liine = NULL;
		env.tab[env.i] = (int *)malloc(sizeof(int) * get_y(str));
		env.j = -1;
		while (str[++(env.j)])
		{
			env.tab[env.i][env.j] = ft_atoi(str[env.j]);
			free(str[env.j]);
		}
		(env.i)++;
	}
	initialisation(&env);
	return (0);
}
