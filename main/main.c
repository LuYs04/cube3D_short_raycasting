#include "cub3d.h"

void    error(char *str)
{
    printf("ERROR: %s", str);
    exit (1);
}

void    start_parsing(int argc, char **argv)
{
    (void)argc;
    if (argc == 1)
        error("missing an argument");
    if (argc > 2)
        error("too many arguments");
    check_extension(argv[1], ".cub");
}

void    get_info_from_file(char *av, t_list **lst, t_list **map, t_lst_txtr **txtr, t_lst_col **col)
{
    int fd;

    fd = open(av, O_RDONLY);
    if (fd == -1)
        error("no such file or directory");
    read_file(lst, fd);
    get_lists(*lst, map, col, txtr);
}

int main(int argc, char **argv)
{
    t_mlx       *mlx;
    t_list      *lst;
    t_list      *map;
    t_lst_col   *col;
    t_lst_txtr  *txtr;

    start_parsing(argc, argv);
    mlx = malloc(sizeof(t_mlx));
    if (!mlx)
        error("memory allocation failed");
    get_info_from_file(argv[1], &lst, &map, &txtr, &col);
    /**************/
    start_the_game(&mlx, txtr, col, map);
    /**************/

    return (0);
}


    // if (len_col(col) != 2 || len_txtr(txtr) != 4)
    //     error("invalid file");
    // printf("\n");
    // print_col(col);
    // printf("\n");
    // print_txtr(txtr);
    // printf("\n");
    // print_lst(map);
    // check_map(mlx->dt->map);
    // mlx = malloc(sizeof(t_mlx));
// }
