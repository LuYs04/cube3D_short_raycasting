#include "../main/cub3d.h"

void read_file(t_list **lst, int fd)
{
	t_list *head;
	char *line;

	head = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		t_list *new_node = ft_lstnew(line);
		if (new_node == NULL)
			error("memory allocation failed");
		if (*lst == NULL)
		{
			*lst = new_node;
			head = new_node;
		}
		else
			ft_lstadd_back(lst, new_node);
	}
	*lst = head;
	if (!head)
		error("invalid file");
}

void ignore_spaces(char **str)
{
	while (*str && (**str == ' ' || **str == '\t'))
		(*str)++;
}

int get_max_line(t_list *map)
{
	t_list *head;
	int line_len;

	head = map;
	line_len = 0;
	while (head)
	{
		if ((int)strlen(map->content) > line_len)
			line_len = (int)strlen(map->content);
		head = head->next;
	}
	return (line_len);
}

char	**lst_map_to_array(t_list *map, int len, int line_len, int i, int j)
{
	char **Map;

	len = ft_lstsize(map);
	if ((char *)map->content == NULL)
		error("invaid file");
	line_len = get_max_line(map);
	Map = malloc((len + 1) * sizeof(char *));
	if (!Map)
		error("memory allocation failed");
	while (++i < len)
	{
		j = -1;
		Map[i] = malloc(line_len + 1);
		if (!Map[i])
			error("memory allocation failed");
		while (++j < line_len)
		{
			// fill_map();
			if (j < (int)strlen((char *)map->content))
				if (((char *)map->content)[j] == '\0' || ((char *)map->content)[j] == '\n')
					Map[i][j] = '*';
				else
					Map[i][j] = ((char *)map->content)[j];
			else
				Map[i][j] = '*';
		}
		Map[i][j] = '\0';
		// printf("%s\n", Map[i]);
		map = map->next;
	}
	Map[i] = NULL;
	return (Map);
}
