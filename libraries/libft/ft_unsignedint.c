/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:51:47 by djareno           #+#    #+#             */
/*   Updated: 2025/08/20 13:04:02 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsignednbr(unsigned int n)
{
	char	buffer[11];
	int		i;
	int		cont;

	i = 0;
	cont = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		cont++;
	}
	while (n)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
		cont++;
	}
	while (i--)
	{
		write(1, &buffer[i], 1);
	}
	return (cont);
}

int	ft_unsignedint(unsigned int n, int cont)
{
	if (!n)
	{
		ft_putchar_fd('0', 1);
		return (cont + 1);
	}
	cont += ft_putunsignednbr(n);
	return (cont);
}
