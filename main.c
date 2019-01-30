/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:56:03 by azarzor           #+#    #+#             */
/*   Updated: 2019/01/30 15:29:06 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdio.h>

void show_me(t_env env)
{
	int i;
	int j;

	i = 0;
	while (i < env.i)
	{
		j = 0;
		while (j < env.j)
		{
			ft_putnbr(env.tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
int get_x(int fd, char *line)
{

	int i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
		i++;
	return (i);
}
int get_y(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int main(int argc, char **argv)
{
	int fd;
	char *liine = NULL;
	t_env env;
	char **str;
	int x;

	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, 1000, 1000, "1337 mlx");
	if (argc != 2)
		ft_putstr("Error\n");
	fd = open(argv[1], O_RDONLY);
	x = get_x(fd, liine);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	env.tab = (int **)malloc(sizeof(int *) * x);
	env.i = 0;
	while (get_next_line(fd, &liine) > 0)
	{
		str = ft_strsplit(liine, ' ');
		env.tab[env.i] = (int *)malloc(sizeof(int) * get_y(str));
		env.j = -1;
		while (str[++(env.j)])
			env.tab[env.i][env.j] = ft_atoi(str[env.j]);
		(env.i)++;
	}
	env.hy = env.i / 2;
	env.hx = env.j / 2;
	env.u = 0;
	env.z = 30;
	grid(env);
	show_me(env);
	mlx_key_hook(env.win_ptr, &key_stroke, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
