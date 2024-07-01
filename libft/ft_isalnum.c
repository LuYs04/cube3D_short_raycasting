/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:33:32 by luatshem          #+#    #+#             */
/*   Updated: 2023/01/23 12:49:05 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
//finished
int	ft_isalnum(int arg)
{
	if (arg >= 48 && arg <= 57)
		return (!NULL);
	else if ((arg >= 65 && arg <= 90) || (arg >= 97 && arg <= 122))
		return (!NULL);
	else
		return (0);
}
/*int main(){
    printf("%d\n", ft_isalnum('5'));
    printf("%d\n", ft_isalnum('a'));
    printf("%d\n", ft_isalnum('H'));
    printf("%d\n", ft_isalnum('/'));
    printf("%d\n", isalnum('5'));
    printf("%d\n", isalnum('a'));
    printf("%d\n", isalnum('H'));
    printf("%d\n", isalnum('/'));

    return (0);
}*/
