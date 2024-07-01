#include "../main/cub3d.h"

void print_lst(t_list *lst)
{
    while (lst)
    {
        printf("%s", lst->content);
        lst = lst->next;
    }
}

void print_txtr(t_lst_txtr *txtr)
{
    while (txtr)
    {
        printf("%s  %s", txtr->pos, txtr->path);
        txtr = txtr->next;
    }
}

void print_col(t_lst_col *col)
{
    while (col)
    {
        printf("%c %d, %d, %d\n", col->pos, col->r, col->g, col->b);
        col = col->next;
    }
}
int    len_txtr(t_lst_txtr *t)
{
    int i;

    i = 0;
    while (t)
    {
        i++;
        t = t->next;
    }
    return (i);
}

int    len_col(t_lst_col *c)
{
    int i;

    i = 0;
    while (c)
    {
        i++;
        c = c->next;
    }
    return (i);
}
