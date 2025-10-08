/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:18:37 by djareno           #+#    #+#             */
/*   Updated: 2025/09/24 11:48:56 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisnum(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	if (x > 10)
		return (-1);
	x = 0;
	if (str[0] == 45)
		x++;
	while (str[x])
	{
		if ((str[x] >= 48 && str[x] <= 57))
			x++;
		else
			return (-1);
	}
	return (0);
}
