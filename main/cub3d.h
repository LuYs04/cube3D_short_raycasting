#ifndef CUB3D_H
#define CUB3D_H

#include "mlx.h"
#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/get_next_line.h"
#include "../libft/libft.h"

# define HEIGHT 1000
# define WIDTH  1500
# define SIZE   8
# define FOV    60
# define RAD    0.01745
# define PI     3.14

// # define ROTATE_SPEED	0.15
# define MOVE_SPEED		0.2

# define RIGHT			124
# define LEFT			123
# define ESC			53
# define Q				12
# define A				0
# define S				1
# define D				2
# define W				13

typedef struct s_lst_txtr
{ 
    char    *pos;
    char    *path;
    struct s_lst_txtr *next;
}       t_lst_txtr;

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

typedef struct s_lst_col
{
    char    pos;
    int     r;
    int     g;
    int     b;
    struct s_lst_col *next;
}       t_lst_col;

typedef struct  s_data
{
    char    **map;
    float   mapX;
    float   mapY;
    int		rate;
	int		neg;
	long	frames;
    double  wallDist;
}       t_data;

typedef struct  s_player
{
    double     x;
    double     y;
    char    dir;
}       t_player;

typedef struct s_ray
{
    float   angle;
    float   angle_pp; // angle++
    float   cos;
    float   sin;
    float   fov; // field of view
    float   lim; //vor pati mej chmtni
    int     accuracy; //chshtutyun
}       t_ray;

typedef struct s_image
{
	int		height;
	int		width;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}       t_image;

typedef struct s_txtr
{
	t_image	*n;
	t_image	*s;
	t_image	*w;
	t_image	*e;
	t_image	*b;
}	t_txtr;

typedef struct s_clr
{
	long	t;
	long	r;
	long	g;
	long	b;
}	t_clr;

typedef struct s_keys
{
    int l;
    int r;
    int up;
    int down;
    int l_rot;
    int r_rot;
}       t_keys;

typedef struct s_cube
{
    int         ceiling;
    int         floor;
    t_keys      *keys;
    t_txtr      *txtr;
    t_data      *dt;
    t_ray       *ray;
    t_player    *ply;
}       t_cube;

typedef struct  s_mlx
{
    void        *mlx_p;
    void        *win;
    t_image     win_img;
    t_cube      *cube;
}       t_mlx;

void    get_info(t_lst_col **col, t_lst_txtr **txtr, t_list **map, char *s, t_list **head);
void    get_lists(t_list  *lst, t_list  **map, t_lst_col **col, t_lst_txtr **txtr);
void    start_the_game(t_mlx **mlx, t_lst_txtr *txtr, t_lst_col *col, t_list *map);
char    **lst_map_to_array(t_list *map, int len, int line_len, int i, int j);
void    free_structs(t_lst_txtr *txtr, t_lst_col *col, t_list *lst);
void	init_player_pos(t_cube *cube, int i, int j);
void    get_colors(t_lst_col **col, char *str);
void    init_cube(t_mlx **mlx, t_list *map);
void	draw_f_c(t_mlx *mlx, int c, int f);
int     key_manager1(int key, t_mlx **mlx);
int     key_manager2(int key, t_cube **c);
void	init_ray(t_cube *cube);
void	update_move(t_cube *cub);
float	degree_to_radians(float degree);
void    read_file(t_list **lst, int fd);
void    get_player_data(t_cube **cube);
void    print_txtr(t_lst_txtr *txtr);
void    check_before_split(char *s);
void    check_extension(char *str, char *s);
int     check_is_that_map(char *s);
void    check_col_line(char *line);
void    get_the_rays(t_mlx **mlx);
void    ignore_spaces(char **str);
void    check_rgb(t_lst_col *col);
void    print_col(t_lst_col *col);
void    check_txtr_pos(char *str);
int     get_max_line(t_list *map);
int     len_txtr(t_lst_txtr *t);
void    free_data(t_mlx **mlx);
void    print_lst(t_list *lst);
void    free_lst(t_list *lst);
int     len_col(t_lst_col *c);
void    init_mlx_params(t_mlx **mlx);
void    check_map(char **map);
int     img_init(t_mlx *data);
int     check_col(char *c);
void    error(char *str);


void raycasting(t_mlx *mlx);
void	color_inverter(t_mlx *mlx);
// int	get_shadow_color(int color, float ds, int tr);
int	color_trgb(int r, int g, int b);
t_image	*mlx_load_img(void *ptr, char *path);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	my_mlx_area_put(t_image *d, t_vector p, t_vector dim, int c);
void	mlx_img_to_img(int p[2], t_image img[2], int c1);
unsigned int	my_mlx_pixel_get(t_image *data, int x, int y);
void	redraw_elem(t_cube *g, t_image img, int x, int y);
void	update_anim(t_cube *cub);
int     cub_update(void *param);
void	draw_texture(t_mlx *mlx, t_image *i, int ray_count, int wall_height);
int	get_tex_color(t_cube *cub, t_image *img, int z);
t_image	*txtr_to_img(t_cube *cub);
t_list	*get_tex(t_image *img, t_list **anim, int n[0][2]);
t_vector	ft_newvector(int x, int y);
void	cub_draw(t_mlx *mlx, int r_count, float dist);


#endif