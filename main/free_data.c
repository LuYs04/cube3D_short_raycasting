#include "cub3d.h"

void    free_data(t_mlx **mlx)
{
    free((*mlx)->cube->ray);
    free((*mlx)->cube->ply);
    // free((*mlx)->cube->dt->map); ????
    free((*mlx)->cube->dt);
    free((*mlx)->cube);
    free((*mlx)->win);
    free((*mlx)->mlx_p);
    free((*mlx)->win);
}

void    free_txtr(t_lst_txtr *txtr)
{
    t_lst_txtr *tmp;

    while (txtr)
    {
        free(txtr->pos);
        free(txtr->path);
        tmp = txtr;
        txtr = txtr->next;
        free(tmp);
    }
}

void    free_col(t_lst_col *col)
{
    t_lst_col *tmp;

    while (col)
    {
        tmp = col;
        col = col->next;
        free(tmp);
    }
}

void    free_lst(t_list *lst)
{
    t_list *tmp;

    while (lst)
    {
        free(lst->content);
        tmp = lst;
        lst = lst->next;
        free(tmp);
    }
}

void    free_structs(t_lst_txtr *txtr, t_lst_col *col, t_list *lst)
{
    free_col(col);
    free_txtr(txtr);
    free_lst(lst);
}
