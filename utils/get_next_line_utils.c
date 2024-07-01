/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:08:41 by luatshem          #+#    #+#             */
/*   Updated: 2023/04/08 17:25:21 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <string.h>

int	ft_nl(const char *s, int c)
{
	int	j;

	j = 0;
	if (s)
		while (s[j] != (unsigned char)c)
			if (!s[j++])
				return (-1);
	return (j);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*t;

	if (!s1 && !*s2)
		return (NULL);
	if (s1)
		t = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	else
		t = malloc((ft_strlen(s2) + 1) * sizeof(char));
	if (!t)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		t[i++] = s2[j++];
	t[i] = '\0';
	if (s1)
		free(s1);
	return (t);
}
