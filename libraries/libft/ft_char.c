/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:07:21 by djareno           #+#    #+#             */
/*   Updated: 2025/08/20 13:04:19 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char(va_list args, int cont)
{
	char	t;

	t = va_arg(args, int);
	cont++;
	ft_putchar_fd(t, 1);
	return (cont);
}
