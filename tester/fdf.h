#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "./minilibx/mlx.h"

# define SCREEN_WIDHT   500
# define SCREEN_HEIGHT  500

typedef struct s_fdf
{
    void    *mlx;
    void    *win;
    void    *img;

} t_fdf;

void	set_cntl(t_fdf *fdf);



#endif