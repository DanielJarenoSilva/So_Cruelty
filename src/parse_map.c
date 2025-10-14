/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:40:54 by djareno           #+#    #+#             */
/*   Updated: 2025/10/14 15:19:33 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all_ones(t_map *map, int i, int y)
{
	y = 0;
	while (map->map[i][y + 1])
	{
		if (map->map[i][y] != '1')
			return (-1);
		y++;
	}
	return (0);
}

int	check_walls(t_map *map)
{
	int	i;
	int	y;

	i = 0;
	while (map->map[i])
	{
		y = 0;
		if (i == 0 || i == map->height - 1)
		{
			if (all_ones(map, i, y) == -1)
				return (-1);
		}
		else
		{
			while (map->map[i][y])
			{
				if ((y == 0 || y == map->length) && map->map[i][y] != '1')
					return (-1);
				y++;
			}
		}
		i++;
	}
	return (0);
}

int	check_conts(t_map *map)
{
	int	i;
	int	y;

	i = 0;
	while (map->map[i])
	{
		y = 0;
		while (map->map[i][y])
		{
			if (map->map[i][y] == 'P')
				map->cnt_p++;
			else if (map->map[i][y] == 'E')
				map->cnt_e++;
			else if (map->map[i][y] == 'C')
				map->cnt_c++;
			else if (map->map[i][y] != '0' && map->map[i][y] != '1')
				return (-1);
			y++;
		}
		i++;
	}
	return (1);
}

int	parse_map(t_map	*map)
{
	if (check_size(map) == -1 || check_walls(map) == -1)
		return (-1);
	if (check_conts(map) == -1)
		return (-1);
	if (map->cnt_c <= 0 || map->cnt_e != 1 || map->cnt_p != 1)
		return (-1);
	if (check_reacheable(map) == -1)
		return (-1);
	return (0);
}

char	**read_map(char	*map)
{
	int		fd;
	char	*str_map;
	char	*line;

	str_map = "";
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		str_map = ft_strjoin(str_map, " ");
		str_map = ft_strjoin(str_map, line);
		str_map = ft_strrmchar(str_map, '\n');
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (ft_split(str_map, ' '));
}
