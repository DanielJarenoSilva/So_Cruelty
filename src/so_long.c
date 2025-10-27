/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:01:58 by djareno           #+#    #+#             */
/*   Updated: 2025/10/21 10:46:12 by djareno          ###   ########.fr       */
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
	tmap->player_in_exit = 0;
	tmap->collectibes_collected = 0;
	tmap->cont_moves = 0;
	return (tmap);
}

int	check_size(t_map *map)
{
	int		i;
	int		size;

	i = 1;
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

void	free_textures(mlx_t *mlx, t_textures *txt)
{
	mlx_delete_image(mlx, txt->img_wall);
	mlx_delete_image(mlx, txt->img_col);
	mlx_delete_image(mlx, txt->img_exit);
	mlx_delete_image(mlx, txt->img_floor);
	mlx_delete_image(mlx, txt->img_player);
	mlx_delete_image(mlx, txt->img_infierno);
	mlx_delete_image(mlx, txt->img_jorker);
	mlx_delete_image(mlx, txt->img_crujiente);
	mlx_delete_image(mlx, txt->img_musk);
	mlx_delete_image(mlx, txt->img_umberto);
	free (txt);
}

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
