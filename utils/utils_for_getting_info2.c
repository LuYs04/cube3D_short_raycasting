#include "../main/cub3d.h"

void    get_colors(t_lst_col **col, char *str)
{
    static t_lst_col *head;
    t_lst_col *temp;
    static int i;

    (*col)->pos = ((char *)(str++))[0];
    (*col)->r = ft_atoi(ft_split(ft_split(str, ',')[0], ' ')[0]);
    (*col)->g = ft_atoi(ft_split(ft_split(str, ',')[1], ' ')[0]);
    (*col)->b = ft_atoi(ft_split(ft_split(str, ',')[2], ' ')[0]);
    (*col)->next = NULL;
    check_rgb(*col);
    if (i++ == 0)
        head = *col;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = *col;
    }
    if (i == 2)
    {
        *col = head;
        return ;
    }
    *col = (*col)->next;
}

void    get_texture(t_lst_txtr **txtr, char *s)
{
    static int          i;
    static t_lst_txtr   *head;
    t_lst_txtr          *temp;

    (*txtr)->pos = ft_split(s, ' ')[0];
    (*txtr)->path = ft_split(ft_split(s, ' ')[1], '\n')[0];
    (*txtr)->next = NULL;
    if (i++ == 0)
        head = *txtr;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = *txtr;
    }
    if (i == 4)
    {
        *txtr = head;
        return ;
    }
    *txtr = (*txtr)->next;
}

void    get_map(t_list **map, char *s, t_list **head)
{
    static int      i;
    t_list          *temp;

    *map = malloc(sizeof(t_list));
    if (!*map)
        error("memory allocation failed");
    (*map)->content = s;
    if (i++ == 0)
        *head = *map;
    else
    {
        temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = *map;
    }
    (*map)->next = NULL;
    *map  = (*map)->next;
}

void    get_info(t_lst_col **col, t_lst_txtr **txtr, t_list **map, char *s, t_list **head)
{
    if (check_is_that_map(s) == -1)
        get_map(map, s, head);
    else
    {
        ignore_spaces((char **)&(s));
        if (check_col(((char *)s)))
        {
            check_col_line((char *)s);
            *col = malloc(sizeof(t_lst_col));
            if (!*col)
                error("memory allocation failed");
            check_before_split((char *)s);
            get_colors(col, s);
        }
        else
        {
            check_txtr_pos((char *)s);
            *txtr = malloc(sizeof(t_lst_txtr));
            if (!*txtr)
                error("memory allocation failed");
            get_texture(txtr, s);
        }
    }
}

void    get_lists(t_list  *lst, t_list  **map, t_lst_col **col, t_lst_txtr **txtr)
{
    t_list   *head_of_map;

    while (lst)
    {
        if (strcmp((char *)lst->content, "\n"))
        {
            if (check_is_that_map(lst->content) == -1
                && ((!(*col) && !(*txtr)) || ((*col) && !(*txtr)) || (!(*col) && (*txtr))))
                error("invalid file");
            get_info(col, txtr, map, lst->content, &head_of_map);
        }
        lst = lst->next;
    }
    *map = head_of_map;
}
