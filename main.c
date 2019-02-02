/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:56:03 by azarzor           #+#    #+#             */
/*   Updated: 2019/02/02 13:42:42 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdio.h>

int			get_x(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
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
	int resx;
	int resy;

	env->a = 0.523599;
	env->c = 0.523599;
	env->hy = env->i / 2;
	env->hx = env->j / 2;
	env->u = 0;
	env->z = 20;
	env->clrd = 0xFFFFFF;
	env->clru = 0xFFD700;
	env->p = 0;
	env->mlx_ptr = mlx_init();
	resx = env->i * 60;
	resy = env->j * 30;
	(resx > 2900) ? resx = 2900 : 1;
	(resy > 1600) ? resy = 1600 : 1;
	env->win_ptr = mlx_new_window(env->mlx_ptr, resx,
			resy, "FDF");
	grid(*env);
	mlx_hook(env->win_ptr,2 ,0 , &key_stroke, env);
	mlx_loop(env->mlx_ptr);
}

void		func(char **argv, t_env *env, int x)
{
	int			fd;
	char		*liine;
	char		**str;

	fd = open(argv[1], O_RDONLY);
	env->tab = (int **)malloc(sizeof(int *) * x);
	env->i = 0;
	while (get_next_line(fd, &liine) > 0)
	{
		str = ft_strsplit(liine, ' ');
		free(liine);
		liine = NULL;
		env->tab[env->i] = (int *)malloc(sizeof(int) * get_y(str));
		env->j = -1;
		while (str[++(env->j)])
		{
			env->tab[env->i][env->j] = ft_atoi(str[env->j]);
			free(str[env->j]);
		}
		(env->i)++;
	}
}

int			main(int argc, char **argv)
{
	t_env		env;
	int			fd;
	int			x;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	x = get_x(fd);
	close(fd);
	func(argv, &env, x);
	initialisation(&env);
	return (0);
}
