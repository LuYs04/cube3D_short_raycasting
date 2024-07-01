#include "../main/cub3d.h"

void	draw_f_c(t_mlx *mlx, int c, int f)
{
	int	i;
	int	j;

	(void)c; (void)f;
	i = -1;
	while (++i < HEIGHT / 2)
	{
		j = -1;
		while (++j < WIDTH)
			my_mlx_pixel_put(&mlx->win_img, j, i, c);//0xde1a24);
	}
	i = HEIGHT / 2 - 1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			my_mlx_pixel_put(&mlx->win_img, j, i, f);//0x759116);
	}
	mlx_put_image_to_window(mlx->mlx_p, mlx->win, mlx->win_img.img, 0, 0);
}

// void	draw_ceiling_and_floor(t_cube *cub)
// {
// 	unsigned int	*dst;
// 	unsigned int	i;

	
// 	dst = (unsigned int *)cub->win_img.addr;
// 	i = WIDTH * HEIGHT / 2 + 1;
// 	while (--i > 0)
// 		*dst ++ = cub->tex.ceiling;
// 		// *dst ++ = 0x0099FFFF;
// 	i = WIDTH * HEIGHT / 2 + 1;
// 	while (--i > 0)
// 		*dst ++ = cub->tex.floor;
// 		// *dst ++ = 0x0099FF00;
// }

// +
void	create_trgb(int color, int *r, int *g, int *b)
{
	// *t = (color >> 24) & 0xFF;
	*r = (color >> 16) & 0xFF;
	*g = (color >> 8) & 0xFF;
	*b = color & 0xFF;
}
// +
int	color_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
// +
int	get_shadow_color(int color, float ds, int tr)
{
	int	c[3];
	float	diff;

	(void)tr;
	if (ds < 0)
		ds = 0;
	diff = powf(1.14, ds / 7.5);
	create_trgb(color, &c[0], &c[1], &c[2]);
	c[0] -= diff;
	c[1] -= diff;
	c[2] -= diff;
	if (c[0] < 0)
		c[0] = 0;
	if (c[1] < 0)
		c[1] = 0;
	if (c[2] < 0)
		c[2] = 0;
	return (color_trgb(c[0], c[1], c[2]));
}

void	color_inverter(t_mlx *mlx)
{
	int	x;
	int	y;

	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
		{
			my_mlx_pixel_put(&mlx->win_img, y, x, 0xFFFFFF - \
				my_mlx_pixel_get(&mlx->win_img, y, x));
		}
	}
}
// +
void	cub_draw(t_mlx *mlx, int r_count, float dist)
{
	int		wall_height;
	float	ds;
	int		i;

	wall_height = (int)(HEIGHT / (1.5 * dist));
	ds = ((float)HEIGHT / 2) - (float)wall_height;
	i = -1;
	while (++i < HEIGHT)
	{
		if (i < ds)
			my_mlx_pixel_put(&mlx->win_img, r_count, i, mlx->cube->ceiling);
				// get_shadow_color(mlx->cube->ceiling, i, 0));
		else if (i >= (HEIGHT / 2) + wall_height)
			my_mlx_pixel_put(&mlx->win_img, r_count, i, mlx->cube->floor);
				// get_shadow_color(mlx->cube->floor, HEIGHT - i, 0));
	}
	// printf("[%d]\n", wall_height);
	draw_texture(mlx, txtr_to_img(mlx->cube), r_count, wall_height);
}
