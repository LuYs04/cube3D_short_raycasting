#include "../main/cub3d.h"

float	degree_to_radians(float degree)
{
	return (degree * RAD);
}

void	moving(int k, t_cube *cube)
{
	float	angle;
	float	r_sin;
	float	r_cos;

	angle = cube->ray->angle;
	if (k == A)
		angle = cube->ray->angle - 90;
	else if (k == S)
		angle = cube->ray->angle - 180;
	else if (k == D)
		angle = cube->ray->angle + 90;
	r_cos = cos(degree_to_radians(angle)) * MOVE_SPEED;
	r_sin = sin(degree_to_radians(angle)) * MOVE_SPEED;
	if (cube->dt->map[(int)(cube->ply->x + 0.5 + \
			(3 * r_sin))][(int)(cube->ply->y + 0.5)] == '0')
		cube->ply->x += r_sin;
	if (cube->dt->map[(int)(cube->ply->x + 0.5)][(int)(cube->ply->y + 0.5 + \
		(3 * r_cos))] == '0')
		cube->ply->y += r_cos;
}

void	ft_exit(t_mlx **mlx)
{
	free_data(mlx);
	printf("end of the game\n");
	exit(0);
}

int	key_manager1(int key, t_mlx **mlx)
{
	if (key == ESC || key == Q)
		ft_exit(mlx);
	if (key == LEFT)
	{
		printf("left rotate pressed\n");
		printf(">>>>>>> %d\n", (*mlx)->cube->keys->l_rot);
		(*mlx)->cube->keys->l_rot = 1;
	}
	if (key == RIGHT)
	{
		printf("right rotate pressed\n");
		printf(">>>>>>> %d\n", (*mlx)->cube->keys->r_rot);
		(*mlx)->cube->keys->r_rot = 1;
	}
	if (key == W)
	{
		printf("up  pressed\n");
		printf(">>>>>>> %d\n", (*mlx)->cube->keys->up);
		(*mlx)->cube->keys->up = 1;
	}
	if (key == A)
	{
		printf("left  pressed\n");
		printf(">>>>>>> %d\n", (*mlx)->cube->keys->l);
		(*mlx)->cube->keys->r = 1;
	}
	if (key == S)
	{
		printf("down pressed\n");
		printf(">>>>>>> %d\n", (*mlx)->cube->keys->down);
		(*mlx)->cube->keys->down = 1;
	}
	if (key == D)
	{
		printf("right  pressed\n");
		printf(">>>>>>> %d\n", (*mlx)->cube->keys->r);
		(*mlx)->cube->keys->l = 1;
	}
	return (0);
}

int	key_manager2(int key, t_cube **c)
{
	if (key == ESC)
		// ft_exit();
	if (key == LEFT)
	{
		printf("left rotate ISN'T pressed\n");
		(*c)->keys->l_rot = 0;
	}
	if (key == RIGHT)
	{
		printf("right rotate ISN'T pressed\n");
		(*c)->keys->r_rot = 0;
	}
	if (key == W)
	{
		printf("up ISN'T pressed\n");
		(*c)->keys->up = 0;
	}
	if (key == A)
	{
		printf("left ISN'T pressed\n");
		(*c)->keys->l = 0;
	}
	if (key == S)
	{
		printf("down ISN'T pressed\n");
		(*c)->keys->down = 0;
	}
	if (key == D)
	{
		printf("right ISN'T pressed\n");
		(*c)->keys->r = 0;
	}
	return (0);
}

void	update_move(t_cube *cub)
{
	if (cub->keys->l_rot)
		cub->ray->angle -= 3;
	printf("-------%d\n", cub->keys->r_rot);
	// printf("[%f]\n",155.7);
	if (cub->keys->r_rot)
	{
		// cub->dt->neg *= -1;
		cub->ray->angle += 3;
	}
	if (cub->keys->up)
		moving(W, cub);
	if (cub->keys->down)
		moving(S, cub);
	if (cub->keys->l)
		moving(A, cub);
	if (cub->keys->r)
		moving(D, cub);
}

// int	do_that_move(int key, t_mlx *mlx)
// {
// 	if (key == ESC)
// 		exit(0);
// 	if (key == LEFT)
// 	{
// 		printf("left rotate\n");
// 		mlx->cube->ray->angle -= 3;
// 	}
// 	if (key == RIGHT)
// 	{
// 		printf("right rotate\n");
// 		mlx->cube->dt->neg *= -1;
// 		mlx->cube->ray->angle += 3;
// 	}
// 	if (key == W)
// 	{
// 		printf("up -> x=%f, y=%f\n", mlx->cube->ply->x, mlx->cube->ply->y);
// 		moving(W, mlx->cube);
// 	}
// 	if (key == A)
// 	{
// 		printf("left -> x=%f, y=%f\n", mlx->cube->ply->x, mlx->cube->ply->y);
// 		moving(A, mlx->cube);
// 	}
// 	if (key == S)
// 	{
// 		printf("down -> x=%f, y=%f\n", mlx->cube->ply->x, mlx->cube->ply->y);
// 		moving(S, mlx->cube);
// 	}
// 	if (key == D)
// 	{
// 		printf("right -> x=%f, y=%f\n", mlx->cube->ply->x, mlx->cube->ply->y);
// 		moving(D, mlx->cube);
// 	}
// 	// img_init(mlx);
// 	return (0);
// }
