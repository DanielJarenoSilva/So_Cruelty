/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:46:49 by djareno           #+#    #+#             */
/*   Updated: 2025/08/20 13:04:42 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_switch(va_list args, char const *format, int x, int cont)
{
	if (format[x] == 's')
		cont = ft_string(args, cont);
	else if (format[x] == 'i')
		cont = ft_int(args, cont);
	else if (format[x] == 'c')
		cont = ft_char(args, cont);
	else if (format[x] == 'd')
		cont = ft_int(args, cont);
	else if (format[x] == '%')
	{
		ft_putchar_fd('%', 1);
		cont++;
	}
	else if (format[x] == 'u')
		cont = ft_unsignedint(va_arg(args, unsigned int), cont);
	else if (format[x] == 'x')
		cont = ft_hexadecimal(args, 1, cont);
	else if (format[x] == 'X')
		cont = ft_hexadecimal(args, 2, cont);
	else if (format[x] == 'p')
		cont = ft_hexadecimalpointer(args, cont) + 2;
	return (cont);
}

int	ft_printf(char const *format, ...)
{
	int		x;
	int		cont;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	x = 0;
	cont = 0;
	while (format[x])
	{
		if (format[x] != '%')
		{
			write(1, &format[x], 1);
			cont++;
		}
		else
		{
			x++;
			cont = ft_switch(args, format, x, cont);
		}
		x++;
	}
	va_end(args);
	return (cont);
}
