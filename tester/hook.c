
#include "fdf.h"

int	quit(void *param)
{
	(void)param;
	exit(0);
}
int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;

	if (key == 53)
		exit(0);
	return (0);
}


void	set_cntl(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0L, key_press, fdf);
	mlx_hook(fdf->win, 17, 0L, quit, fdf);
}
