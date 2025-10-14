/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:00:09 by djareno           #+#    #+#             */
/*   Updated: 2025/10/13 13:47:16 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	main(void)
{
    ft_putnbr_fd(rand_range(0, 10), 1);
    ft_putnbr_fd(rand_range(0, 10), 1);
    ft_putnbr_fd(rand_range(0, 10), 1);
    ft_putnbr_fd(rand_range(0, 10), 1);
	return (0);
}

