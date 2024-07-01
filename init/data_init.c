#include "../main/cub3d.h"

void    init_data(t_cube **cube, t_list *map)
{
    (*cube)->dt = malloc(sizeof(t_data));
    if (!(*cube)->dt)
        error("memory allocation failed");
    (*cube)->dt->map = lst_map_to_array(map, -1, -1, -1, -1);
    (*cube)->dt->mapX = 0.0;
    (*cube)->dt->mapY = 0.0;
    get_player_data(cube);
    (*cube)->dt->rate = 30;
    (*cube)->dt->neg = 0;
    (*cube)->dt->frames = 0;
    (*cube)->dt->wallDist = 0.0;
}

void    init_plyr(t_cube **cube)
{
    (*cube)->ply = malloc(sizeof(t_player));
    if (!(*cube)->ply)
        error("memory allocation failed");
    (*cube)->ply->x = -1;
    (*cube)->ply->y = -1;
    (*cube)->ply->dir = 0;
}

void	init_ray(t_cube *cube)
{
    cube->ray = malloc(sizeof(t_ray));
    if (!cube->ray)
        error("memory allocation failed");
	if (cube->ply->dir == 'N')
		cube->ray->angle = 270;
	else if (cube->ply->dir == 'W')
		cube->ray->angle = 180;
	else if (cube->ply->dir == 'S')
		cube->ray->angle = 90;
	else
		cube->ray->angle = 0;
	cube->ray->fov = 30;
	cube->ray->angle_pp = 2 * cube->ray->fov / WIDTH;
	cube->ray->accuracy = 50;
	cube->ray->lim = 11;
}

void    malloc_txtrs(t_txtr **t)
{
    (*t)->n = malloc(sizeof(t_image));
    (*t)->s = malloc(sizeof(t_image));
    (*t)->e = malloc(sizeof(t_image));
    (*t)->w = malloc(sizeof(t_image));
}

void    init_txtr(t_cube **cub)
{
    (*cub)->txtr = malloc(sizeof(t_txtr));
    if (!(*cub)->txtr)
        error("memory allocation failed");
    malloc_txtrs(&(*cub)->txtr);
    (*cub)->txtr->n = NULL;
    (*cub)->txtr->s = NULL;
    (*cub)->txtr->w = NULL;
    (*cub)->txtr->e = NULL;
}

void    init_keys(t_keys **k)
{
    *k = malloc(sizeof(t_keys));
    if (!*k)
        error("memory allocation failed");
    (*k)->l = 0;
    (*k)->r = 0;
    (*k)->up = 0;
    (*k)->down = 0;
    (*k)->l_rot = 0;
    (*k)->r_rot = 0;
}

void    init_cube(t_mlx **mlx, t_list *map)
{
    (*mlx)->cube = malloc(sizeof(t_cube));
    if (!(*mlx)->cube)
        error("memory allocation failed");
    (*mlx)->cube->ceiling = 0;
    (*mlx)->cube->floor = 0;
    init_keys(&(*mlx)->cube->keys);
    init_txtr(&(*mlx)->cube);
    init_plyr(&(*mlx)->cube);
    init_data(&(*mlx)->cube, map);
    (*mlx)->cube->ply->x = (*mlx)->cube->dt->mapX;
    (*mlx)->cube->ply->y = (*mlx)->cube->dt->mapY;
    init_ray((*mlx)->cube);
}
