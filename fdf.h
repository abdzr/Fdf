
#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <mlx.h>

# define BUFF_SIZE 32

typedef struct s_point
{
    int x;
    int y;
    int z;
}           t_point;

typedef struct s_env 
{
    void    *mlx_ptr;
    void    *win_ptr;
    int xi;
    int xf;
    int yi;
    int yf;
    int **tab;
    int i;
    int j;
    int u;
    int s;
    int sc;
    float ang;
    int hx;
    int hy;
    int z;
    float crm;
}              t_env;

typedef struct s_line
{
    int x;
    int y;
    int dx;
    int dy;
    int xinc;
    int yinc;
    int cumul;
}               t_line;



int		get_next_line(const int fd, char **line);
int     key_stroke(int key, void *test);
void    line(t_env env);
void    grid(t_env env);
void    show_me(t_env env);
int     get_x(int fd, char *line);
int     get_y(char **str);
void    draw_grid(t_env *env);
#endif