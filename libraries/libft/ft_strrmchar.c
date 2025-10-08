/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrmchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:30:12 by djareno           #+#    #+#             */
/*   Updated: 2025/10/08 13:45:25 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrmchar(char *str, char c)
{
	int				i;
	int				cont;
	char			*newstr;
	unsigned long	y;

	i = 0;
	y = 0;
	cont = 0;
	while (str[i])
	{
		if (str[i++] == c)
			cont++;
	}
	newstr = ft_calloc(ft_strlen(str) - cont, sizeof(char *));
	i = 0;
	while (y < ft_strlen(str) - cont)
	{
		if (str[i] != c)
			newstr[y] = str[i];
		else
			i++;
		y++;
		i++;
	}
	return (newstr);
}
