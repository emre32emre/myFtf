#include "./minilibx/mlx.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_close()
{
	 exit(write(1, "anan", 4));
}

int ft_esc(int keycode)
{
	if (keycode == 53)
		exit(1);
	else
		write(1, "31", 2);
	return (31);
}
void drawLine(int x1, int x2, int y1, int y2, void *mlx , void *mlx_win)
{
	int dx, dy, i, e;
	int incx,incy,inc1,inc2;
	int x, y;

	dx = x2 - x1;
	dy = y2 - y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1;
	y = y1;
	if (dx > dy)
	{
		mlx_pixel_put(mlx,mlx_win,x,y,0xFFFFFF);
		e = 2 * dy - dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for(i = 0;i<dx;i++)
		{
			if(e >= 0)
			{
				y += incy;
				e += inc1;
			}
			else
			{
				e += inc2;
			}
			x += incx;
			mlx_pixel_put(mlx,mlx_win,x,y,0xFFFFFF);
		}
	}
	else
	{
		mlx_pixel_put(mlx,mlx_win,x,y,0xFFFFFF);
		e = 2 *dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for(i = 0;i<dy;i++)
		{
			if(e >= 0)
			{
				x+= incx;
				e += inc1;
			}
			else
			{
				e += inc2;
			}
			y += incy;
			mlx_pixel_put(mlx,mlx_win,x,y,0xFFFFFF);
		}
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 200, 200, "Hello world!");

	
	drawLine(200,175,200,75,mlx,mlx_win);


	mlx_hook(mlx_win, 17, 0,ft_close, 0);
	mlx_hook(mlx_win, 2, 0, ft_esc, 0);
	mlx_loop(mlx);
	
}