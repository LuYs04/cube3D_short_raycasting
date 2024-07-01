/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:28:11 by luatshem          #+#    #+#             */
/*   Updated: 2023/04/10 16:44:38 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *strline, int fd)
{
	char	str[BUFFER_SIZE + 1];
	int		n;

	n = 0;
	while (1)
	{
		n = read(fd, str, BUFFER_SIZE);
		if (n < 0 || (n == 0 && strline == 0))
			break ;
		str[n] = '\0';
		strline = ft_join(strline, str);
		if (ft_nl(strline, '\n') != -1 || n == 0)
			return (strline);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*t;
	char		*line;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (0);
	s = get_line(s, fd);
	if (!s)
		return (0);
	if (ft_nl(s, '\n') >= 0)
	{
		line = ft_substr(s, 0, ft_nl(s, '\n') + 1);
		t = ft_substr(s, ft_nl(s, '\n') + 1, ft_strlen(s) - ft_nl(s, '\n') - 1);
		free(s);
		s = t;
	}
	else
	{
		line = ft_join(line, s);
		free(s);
		s = 0;
	}
	return (line);
}	
