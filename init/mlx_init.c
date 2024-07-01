#include "../main/cub3d.h"

void init_mlx_params(t_mlx **mlx)
{
    (*mlx)->mlx_p = mlx_init();
    (*mlx)->win = mlx_new_window((*mlx)->mlx_p, WIDTH, HEIGHT, "Cube3D");
    (*mlx)->win_img.img = mlx_new_image((*mlx)->mlx_p, 	WIDTH, HEIGHT);
    (*mlx)->win_img.addr = mlx_get_data_addr((*mlx)->win_img.img, &(*mlx)->win_img.bits_per_pixel, \
		&(*mlx)->win_img.line_length, &(*mlx)->win_img.endian);
	// (*mlx)->minimap.img = mlx_new_image((*mlx)->mlx_p, 	WIDTH, HEIGHT); // cub->width * SIZE, cub->height * SIZE
    // (*mlx)->minimap.addr = mlx_get_data_addr((*mlx)->minimap.img, &(*mlx)->minimap.bits_per_pixel, \
	// 	&(*mlx)->minimap.line_length, &(*mlx)->minimap.endian);
	// (*mlx)->miniview.img = mlx_new_image((*mlx)->mlx_p, 30 * SIZE, 15 * SIZE);
    // (*mlx)->miniview.addr = mlx_get_data_addr((*mlx)->miniview.img, &(*mlx)->miniview.bits_per_pixel, \
	// 	&(*mlx)->miniview.line_length, &(*mlx)->miniview.endian);
	// (*mlx)->miniview.width = 30 * SIZE;
	// (*mlx)->miniview.height = 15 * SIZE;
}

int	img_init(t_mlx *data)
{
	if (data->mlx_p && data->win_img.img)
		mlx_destroy_image(data->mlx_p, data->win_img.img);
	data->win_img.img = mlx_new_image(data->mlx_p, WIDTH, HEIGHT);
	data->win_img.addr = mlx_get_data_addr(data->win_img.img, \
			&data->win_img.bits_per_pixel, \
			&data->win_img.line_length, &data->win_img.endian);
	// printf("dfghj\n");
	draw_f_c(data, data->cube->ceiling, data->cube->floor);
	return (0);
}

t_image	*mlx_load_img(void *ptr, char *path)
{
	int		fd;
	t_image	*i;

	i = malloc(sizeof(t_image));
	i->img = NULL;
	check_extension(path, ".xpm");
	// printf("[%s]\n", path);
	fd = open(ft_strjoin("./", path), O_RDONLY);
	// printf("--%s\n", ft_strjoin("./", path));
	// fd = open("./textures/simonkraft/respawn_anchor_side0.xpm", O_RDONLY);
	// printf("%d\n", fd);
	if (fd < 0)
		error("invalid file 1");
	close(fd);
	i->img = mlx_xpm_file_to_image(ptr, path, &i->width, &i->height);
	i->addr = mlx_get_data_addr(i->img, &i->bits_per_pixel, &i->line_length, &i->endian);
	return (i);
}
