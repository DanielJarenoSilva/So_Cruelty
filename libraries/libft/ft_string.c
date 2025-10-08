/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:16:29 by djareno           #+#    #+#             */
/*   Updated: 2025/08/20 13:06:18 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_string(va_list args, int cont)
{
	char	*t;

	t = va_arg(args, char *);
	if (!t)
	{
		ft_putstr_fd("(null)", 1);
		return (cont + 6);
	}
	cont = cont + ft_strlen(t);
	ft_putstr_fd(t, 1);
	return (cont);
}
