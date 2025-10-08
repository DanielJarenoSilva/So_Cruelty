/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:22:01 by djareno           #+#    #+#             */
/*   Updated: 2025/08/20 13:04:30 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(int n)
{
	int	l;

	l = 0;
	if (n < 0)
	{
		n *= -1;
		l++;
	}
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

int	ft_int(va_list args, int cont)
{
	int	t;

	t = va_arg(args, int);
	if (t == 0)
	{
		ft_putchar_fd('0', 1);
		return (cont + 1);
	}
	cont += ft_countdigits(t);
	ft_putnbr_fd(t, 1);
	return (cont);
}
