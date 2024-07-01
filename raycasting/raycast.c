#include "../main/cub3d.h"

t_vector	ft_newvector(int x, int y)
{
	t_vector	position;

	position.x = x;
	position.y = y;
	return (position);
}

void	fill_colors(t_cube **cube, t_lst_col *col)
{
	while (col)
	{
		if (col->pos == 'C')
			(*cube)->ceiling = color_trgb(col->r, col->g, col->b);
		if (col->pos == 'F')
			(*cube)->floor = color_trgb(col->r, col->g, col->b);
		col = col->next;
	}
}

float   get_wall_dist(t_mlx **mlx, float r_angle)
{
    float   dist;
	t_cube *cube;

	cube = (*mlx)->cube;
    cube->ray->sin = sin(degree_to_radians(r_angle)) / cube->ray->accuracy;
	cube->ray->cos = cos(degree_to_radians(r_angle)) / cube->ray->accuracy;
	cube->dt->mapX = cube->ply->x + 0.5;
	cube->dt->mapY = cube->ply->y + 0.5;
	while (!ft_strchr("1", cube->dt->map[(int)cube->dt->mapX][(int)cube->dt->mapY]) && \
		sqrt(powf(cube->dt->mapX - cube->ply->x - 0.5, 2.) + \
		powf(cube->dt->mapY - cube->ply->y - 0.5, 2.)) < cube->ray->lim)
	{
		cube->dt->mapX += cube->ray->sin;
		cube->dt->mapY += cube->ray->cos;
		// if (r_angle - 1 < cube->ray->angle && r_angle + 1 > cube->ray->angle)
		// 	my_mlx_pixel_put((*mlx)->win_img.img, cube->dt->mapY * SIZE, cube->dt->mapX * SIZE, 0x0000FF00); //xi es guyn?
		// else
		// 	my_mlx_pixel_put((*mlx)->win_img.img, cube->dt->mapY * SIZE, cube->dt->mapX * SIZE, 0x00CC66FF); //xi es guyn?
	}
	dist = sqrt(powf(cube->dt->mapX - cube->ply->x - 0.5, 2.) + powf(cube->dt->mapY - cube->ply->y - 0.5, 2.));
	return (dist * cos(degree_to_radians(r_angle - cube->ray->angle)));
}

void raycasting(t_mlx *mlx)
{
    int     r;
    float   r_angle;
    float   dist;

    r = -1;
    r_angle = mlx->cube->ray->angle - mlx->cube->ray->fov;
    while (++r < WIDTH)
    {
        dist = get_wall_dist(&mlx, r_angle);
		// printf("----------%f----\n", dist);
		cub_draw(mlx, r, dist);
        r_angle += mlx->cube->ray->angle_pp;
    }
}

void	fill_textures(t_mlx **mlx, t_lst_txtr *txtr)
{
	while (txtr)
	{
		if (!ft_strncmp(txtr->pos, "NO", 3))
			(*mlx)->cube->txtr->n = mlx_load_img((*mlx)->mlx_p, txtr->path);
		if (!ft_strncmp(txtr->pos, "SO", 3))
			(*mlx)->cube->txtr->s = mlx_load_img((*mlx)->mlx_p, txtr->path);
		if (!ft_strncmp(txtr->pos, "EA", 3))
			(*mlx)->cube->txtr->e = mlx_load_img((*mlx)->mlx_p, txtr->path);
		if (!ft_strncmp(txtr->pos, "WE", 3))
			(*mlx)->cube->txtr->w = mlx_load_img((*mlx)->mlx_p, txtr->path);
		txtr = txtr->next;
	}
}

void    start_the_game(t_mlx **mlx, t_lst_txtr *txtr, t_lst_col *col, t_list *map)
{
    init_mlx_params(mlx);
	init_cube(mlx, map);
	fill_colors(&(*mlx)->cube, col);
	fill_textures(mlx, txtr);
	free_structs(txtr, col, map);
	raycasting(*mlx);
	// printf(">>>>>>> %d\n", (*mlx)->cube->keys->down);
	mlx_hook((*mlx)->win, 02, 1L << 0, key_manager1, &(*mlx)->cube);
	mlx_hook((*mlx)->win, 03, 1L << 1, key_manager2, &(*mlx)->cube);
	mlx_put_image_to_window((*mlx)->mlx_p, (*mlx)->win, (*mlx)->win_img.img, 0, 0);
	mlx_loop_hook((*mlx)->mlx_p, cub_update, *mlx);
    mlx_loop((*mlx)->mlx_p);
}