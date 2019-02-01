/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:33:21 by azarzor           #+#    #+#             */
/*   Updated: 2019/02/01 13:38:46 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <mlx.h>

# define BUFF_SIZE 4000

typedef struct		s_point
{
	int x;
	int y;
	int z;
}					t_point;
typedef struct		s_env
{
	float		a;
	float		c;
	void		*mlx_ptr;
	void		*win_ptr;
	int			**tab;
	int			xi;
	int			xf;
	int			yi;
	int			yf;
	int			i;
	int			j;
	int			u;
	int			s;
	int			sc;
	int			color;
	int			hx;
	int			hy;
	int			z;
	int			p;
}					t_env;
typedef struct		s_line
{
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
	int			cumul;
}					t_line;
int					get_next_line(const int fd, char **line);
int					key_stroke(int key, void *test);
void				line(t_env env);
void				grid(t_env env);
void				show_me(t_env env);
int					get_x(int fd);
int					get_y(char **str);
void				draw_grid(t_env *env);
void				key_stroke_2(int key, void *test);
#endif
