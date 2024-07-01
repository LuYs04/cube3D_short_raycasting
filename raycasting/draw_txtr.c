#include "../main/cub3d.h"

t_list	*get_tex(t_image *img, t_list **anim, int n[0][2])
{
	if (n && anim && *anim && img)
		(*n)[0]--;
	if (!img)
		return (*anim);
	if (!img->img)
	{
		free(img);
		(*n)[1] = 0;
		return (*anim);
	}
	ft_lstadd_back(anim, ft_lstnew(img));
	return (*anim);
}

t_image	*txtr_to_img(t_cube *cub)
{
	t_image	*img;
	float	r_cos;
	float	r_sin;

	r_cos = cub->ray->cos;
	if (r_cos < 0)
		r_cos *= -1;
	// printf("[%f]\n",155.7);
	r_sin = cub->ray->sin;
	if (r_sin < 0)
		r_sin *= -1;
	img = cub->txtr->b;
	if (cub->dt->map[(int)(cub->dt->mapX - r_sin)][(int)cub->dt->mapY] != '1')
		img = cub->txtr->n;
	else if (cub->dt->map[(int)(cub->dt->mapX + r_sin)][(int)cub->dt->mapY] != '1')
		img = cub->txtr->s;
	else if (cub->dt->map[(int)cub->dt->mapX][(int)(cub->dt->mapY + r_cos)] != '1')
		img = cub->txtr->e;
	else if (cub->dt->map[(int)cub->dt->mapX][(int)(cub->dt->mapY - r_cos)] != '1')
		img = cub->txtr->w;
	return (img);
}

int	get_tex_color(t_cube *cub, t_image *img, int z)
{
	int	color;

	color = 0x00000000;
	if (cub->dt->map[(int)cub->dt->mapX][(int)cub->dt->mapY] == '1')
		color = my_mlx_pixel_get(img, (int)(img->width * (cub->dt->mapX + cub->dt->mapY)) \
			% img->width, z);
	return (color);
}

void	draw_texture(t_mlx *mlx, t_image *img, int r_count, int wall_H)
{
	float	dy; // change in height per pixel in the texture
	float	ds; // the starting point for rendering the texture vertically
	float	cy[2];
	int		z;
	int		color;

	dy = ((float)wall_H * 2) / (float)img->height;
	ds = ((float)HEIGHT / 2) - (float)wall_H;
	cy[1] = ds; // initial y-coordinate for drawing 
	z = -1;
	// printf("[[[[[[   %d\n", img->height);
	while (++z < img->height)
	{
		color = get_tex_color(mlx->cube, img, z);
		// color = get_shadow_color(color, ds, 0);
		cy[0] = cy[1];
		while (cy[0] < cy[1] + dy)
		{
			// printf("djvar stexic lini [%f]\n", cy[0]);
			if (cy[0] >= 0 && cy[0] < (float)HEIGHT)
				my_mlx_pixel_put(&mlx->win_img, r_count, cy[0], color);
			cy[0]++;
		}
		cy[1] += dy;
	}
	// printf("haaa  %d\n", z);
}