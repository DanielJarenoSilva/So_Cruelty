/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:01:58 by djareno           #+#    #+#             */
/*   Updated: 2025/10/08 15:59:43 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*init_map(char **map)
{
	t_map	*tmap;

	tmap = malloc(sizeof(t_map));
	tmap->cnt_c = 0;
	tmap->cnt_e = 0;
	tmap->map = map;
	tmap->cnt_p = 0;
	tmap->height = 0;
	tmap->length = 0;
	return (tmap);
}

int	check_size(t_map *map)
{
	int		i;
	int		y;
	int		size;

	i = 1;
	y = 0;
	size = ft_strlen(map->map[0]);
	while (map->map[i])
	{
		if ((int) ft_strlen(map->map[i]) != size)
			return (-1);
		i++;
	}
	map->length = size;
	map->height = i;
	return (0);
}
