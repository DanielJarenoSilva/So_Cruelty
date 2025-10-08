/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:48:50 by djareno           #+#    #+#             */
/*   Updated: 2025/08/20 13:04:09 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_puthexadecimalpointer(unsigned long n, int cont)
{
	char	buffer[20];
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (n == 0)
	{
		write(1, "0", 1);
		return (cont + 1);
	}
	while (n)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		cont++;
	}
	return (cont);
}

static int	ft_puthexadecimal(unsigned int n, int tipo, int cont)
{
	char	buffer[20];
	int		i;
	char	*hex;

	i = 0;
	if (tipo == 1)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n == 0)
	{
		write(1, "0", 1);
		return (cont + 1);
	}
	while (n)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		cont++;
	}
	return (cont);
}

int	ft_hexadecimal(va_list args, int tipo, int cont)
{
	int	x;

	x = va_arg(args, int);
	if (!x)
	{
		ft_putchar_fd('0', 1);
		return (cont + 1);
	}
	cont = ft_puthexadecimal(x, tipo, cont);
	return (cont);
}

int	ft_hexadecimalpointer(va_list args, int cont)
{
	unsigned long	x;

	x = (unsigned long) va_arg(args, void *);
	if (!x)
	{
		ft_putstr_fd("(nil)", 1);
		return (cont + 3);
	}
	write(1, "0x", 2);
	cont = ft_puthexadecimalpointer(x, cont);
	return (cont);
}
