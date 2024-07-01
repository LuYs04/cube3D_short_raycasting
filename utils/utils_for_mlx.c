#include "../main/cub3d.h"

// void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
// {
// 	char	*dest;

// 	dest = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
// 	*(unsigned int *)dest = color;
// }

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_area_put(t_image *d, t_vector p, t_vector dim, int c)
{
	int	x;
	int	y;

	y = -1;
	while (++y < dim.y)
	{
		x = -1;
		while (++x < dim.x)
			my_mlx_pixel_put(d, p.x + x, p.y + y, c);
	}
}

void	mlx_img_to_img(int p[2], t_image img[2], int c1)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	while (++x < img[0].height)
	{
		y = -1;
		while (++y < img[0].width)
		{
			if (y + p[0] >= 0 && x + p[1] >= 0)
			{
				color = my_mlx_pixel_get(&img[0], y, x);
				if (color != c1)
					my_mlx_pixel_put(&img[1], y + p[0], \
						x + p[1], color);
			}
		}
	}
}

unsigned int	my_mlx_pixel_get(t_image *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
