/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:17:52 by djareno           #+#    #+#             */
/*   Updated: 2025/10/14 15:04:59 by djareno          ###   ########.fr       */
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

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->length)
		{
			if (copy[x][y] == 'P')
			{
				player = malloc(sizeof(t_player));
				player->x = x;
				player->y = y;
				return (player);
			}
			y++;
		}
		x++;
	}
	return (NULL);
}

int	is_valid(t_map *map, int valid, char **copy)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->length)
		{
			if (copy[x][y] == 'C' || copy[x][y] == 'E')
			{
				valid = -1;
				return (valid);
			}
			y++;
		}
		x++;
	}
	return (valid);
}

int	check_reacheable(t_map *map)
{
	char		**copy;
	int			valid;
	t_player	*player;

	copy = NULL;
	copy = copy_map(map);
	player = find_player(map, copy);
	if (!player)
		return (-1);
	valid = 1;
	flood_fill(copy, player->x, player->y);
	valid = is_valid(map, valid, copy);
	free (player);
	ft_free_matrix(copy);
	return (valid);
}
