#include "../main/cub3d.h"

int check_col(char *c)
{
    if (c[0] == 'F' || c[0] == 'C')
        return (1);
    return (0);
}

void    check_col_line(char *line)
{
    int i;

    i = 0;
    while (i++ < (int)strlen(line) - 1)
        if (line[i] != ' ' && line[i] != ',' && line[i] != '\n' && !ft_isdigit(line[i]))
            error("invalid file");
}

void    check_txtr_pos(char *str)
{
    if (str && (!(str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
    && !(str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
    && !(str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
    && !(str[0] == 'E' && str[1] == 'A' && str[2] == ' ')))
        error("invalid file");
}

void    check_rgb(t_lst_col *col)
{
    if ((col->r > 255 || col->r < 0) 
        || (col->g > 255 || col->g < 0)
        || (col->b > 255 || col->b < 0))
        error("invalid file");
}

int check_is_that_map(char *s)
{
    int i;

    i = 0;
    while (s[i] && (s[i] == ' ' || s[i] == '0' || s[i] == '1' 
    || s[i] == '\n' || s[i] == 'N' || s[i] == 'S' 
    || s[i] == 'W' || s[i] == 'E'))
        i++;
    if (i != (int)strlen(s))
        return (i);
    return (-1);
}
