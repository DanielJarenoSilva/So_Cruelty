/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:42:31 by djareno           #+#    #+#             */
/*   Updated: 2025/10/13 13:46:51 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_rand(void)
{
	unsigned int	rand_seed;

	rand_seed = (unsigned int)(unsigned long)&my_rand * 1103515245 + 12345;
	return ((rand_seed / 65536) % 32768);
}

int	rand_range(int min, int max)
{
	int	range;

	if (min > max)
		return (-1);
	range = max - min + 1;
	return (my_rand() % range + min);
}
