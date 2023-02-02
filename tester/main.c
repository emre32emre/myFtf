#include "fdf.h"
// g:cc main.c hook.c libmlx.a -framework AppKit -framework OpenGl && ./a.out
int main()
{
    t_fdf *fdf;
    fdf = malloc(sizeof(t_fdf) * 1);

    fdf->mlx = mlx_init();
    fdf->win = mlx_new_window(fdf->mlx,SCREEN_WIDHT,SCREEN_HEIGHT,"sa");

    set_cntl(fdf);
    
    mlx_loop(fdf->mlx);
}