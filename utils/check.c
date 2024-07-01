#include "../main/cub3d.h"

void check_extension(char *str, char *s)
{
    char *ext = strrchr(str, '.'); 

    if (!ext || strcmp(ext, s) != 0)
        error("wrong extension");
}

void    check_before_split(char *s)
{
    int i;
    int count;

    i = 0;
    count = 0;
    s++;
    while (ft_split(s, ',')[i] != NULL)
        i++;
    if (i != 3)
        error("invalid file");
    i = -1;
    if (ft_split(s, ',')[2])
        while (ft_split(s, ',')[2][++i])
            if (ft_isdigit(ft_split(s, ',')[2][i]))
                count++;
    if (!count)
        error("invalid file");
}

int    find_char(char *s, char c)
{
    int     i;
    int     count;

    i = 0;
    count = 0;
    while (s[i])
        if (s[i] == c)
            count++;
    return (count);
}

void    check_map(char **map)
{
    int     i;

    i = -1;
    while (map[++i])
    {
        if (find_char(map[i], '*') == (int)ft_strlen(map[i]) 
        || find_char(map[i], '*') == (int)ft_strlen(map[i]) - 1)
            error("invalid map");
    }
}
