/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 09:11:32 by azarzor           #+#    #+#             */
/*   Updated: 2019/01/21 14:26:58 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <math.h>
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

struct s_params
{
	void *mlx_ptr;
	void *win_ptr;
};
struct s_point
{
	int x;
	int y;
};
typedef struct s_point t_point;
typedef struct s_params t_params;

int destroy(int key, void *test)
{
	t_params *params;
	params = (t_params *)test;
	printf("key : %d\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

void line(t_params params, t_point i, t_point f)
{
	p.x = i.x;
	p.y = i.y;
	dp.x = f.x - i.x;
	dp.y = f.y - i.y;
	inc.x = (dp.x > 0) ? 1 : -1;
	inc.y = (dp.y > 0) ? 1 : -1;
	dp.x = abs(dp.x);
	dp.y = abs(dp.y);
	mlx_pixel_put(params.mlx_ptr, params.win_ptr, p.x, p.y, 0xFFFFFFF);
	if (dp.x > dp.y)
	{
		cumul = dp.x / 2;
		j = 1;
		while (j <= dp.x)
		{
			p.x += inc.x;
			cumul += dp.y;
			if (cumul >= dp.x)
			{
				cumul -= dp.x;
				p.y += inc.y;
			}
			mlx_pixel_put(params.mlx_ptr, params.win_ptr, p.x, p.y, 0xFFFFFFFF);
			j++;
		}
	}
	else
	{
		cumul = dp.y / 2;
		j = 1;
		while (j <= dp.y)
		{
			p.y += inc.y;
			cumul += dp.x;
			if (cumul >= dp.y)
			{
				cumul -= dp.y;
				p.x += inc.y;
				mlx_pixel_put(params.mlx_ptr, params.win_ptr, p.x, p.y, 0xFFFFFF);
				j++;
			}
		}
	}
}
void	rotate(t_point *p)
{
	int oldx;
	oldx = p->x * cos(0.523) - p->y * sin(0.523);
	p->y = p->y * cos(0.523) + p->x * sin(0.523);
	p->x = oldx;
}
int main(void)
{
	t_point pi;
	t_point pf;
	double a;
	double b;
	t_params params;
pi.x = 100;
pi.y = 100;
pf.x = 200;
pf.y = 200;
	params.mlx_ptr = mlx_init();
	params.win_ptr = mlx_new_window(params.mlx_ptr, 500, 500, "mlx 1337");
	line(params,pi,pf);
	printf("x before :%d\n y before :%d\n ",pi.x, pi.y);
	printf("xf before :%d\n yf before :%d\n ",pf.x, pf.y);
rotate(&pi);
rotate(&pf);	
	printf("x after :%d\n y after :%d\n",pi.x, pi.y);
	printf("xf after :%d\n yf after :%d\n",pf.x, pf.y);
	pi.x = 36;
	pi.y = 136;
	pf.x = 73;
	pf.y = 273;
		line(params,pi,pf);
	mlx_key_hook(params.win_ptr, &destroy, &params);
	mlx_loop(params.mlx_ptr);
	return (0);
}
