#include "../main/cub3d.h"

int	cub_update(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	// printf("---------------%d\n", mlx->cube->dt->rate);
	if (!(mlx->cube->dt->frames % mlx->cube->dt->rate))
	{
		update_move(mlx->cube);
		raycasting(mlx);
		if (mlx->cube->dt->neg > 0)
			color_inverter(mlx);
		mlx_put_image_to_window(mlx->mlx_p, mlx->win, mlx->win_img.img, 0, 0);
	}
	mlx->cube->dt->frames++;
	return (0);
}