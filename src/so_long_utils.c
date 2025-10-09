/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:17:52 by djareno           #+#    #+#             */
/*   Updated: 2025/10/09 13:59:20 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'F')
		return ;

	if (map[x][y] == '0' || map[x][y] == 'C'
		|| map[x][y] == 'E' || map[x][y] == 'P')
		map[x][y] = 'F';

	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

char	**copy_map(t_map *map)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);

	while (i < map->height)
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
		{
			while (i--)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[map->height] = NULL;
	return (copy);
}

t_player	*find_player(t_map *map, char **copy)
{
	int			x;
	int			y;
	t_player	*player;

	player = malloc(sizeof(t_player));
	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->length)
		{
			if (copy[x][y] == 'P')
			{
				player->x = x;
				player->y = y;
				return (player);
			}
			y++;
		}
		x++;
	}
	return (player);
}

int	check_reacheable(t_map *map)
{
	int		x;
	int		y;
	char	**copy;
	int		valid;

	copy = copy_map(map);
	valid = 1;
	flood_fill(copy, find_player(map, copy)->x, find_player(map, copy)->y);
	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->length)
		{
			if (copy[x][y] == 'C' || copy[x][y] == 'E')
			{
				valid = -1;
				break ;
			}
			y++;
		}
		x++;
	}
	ft_free_matrix(copy);
	return (valid);
}
