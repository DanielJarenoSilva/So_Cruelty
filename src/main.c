/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:09:05 by djareno           #+#    #+#             */
/*   Updated: 2025/10/08 16:08:48 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(t_map *map)
{
	mlx_t*	mlx;
	int		x;
	int		y;

	mlx = mlx_init(map->length * 64, map->height * 64, "so cruel", true);
	if (!mlx)
		return (-1);
	mlx_texture_t* text_wall = mlx_load_png("textures/wall.png");
	mlx_texture_t* text_floor = mlx_load_png("textures/floor.png");
	mlx_texture_t* text_exit = mlx_load_png("textures/exit.png");
	mlx_texture_t* text_player = mlx_load_png("textures/player.png");
	mlx_texture_t* text_collectible = mlx_load_png("textures/collectible.png");
	
	mlx_image_t* img_wall = mlx_texture_to_image(mlx, text_wall);
	mlx_image_t* img_floor = mlx_texture_to_image(mlx, text_floor);
	mlx_image_t* img_exit = mlx_texture_to_image(mlx, text_exit);
	mlx_image_t* img_player = mlx_texture_to_image(mlx, text_player);
	mlx_image_t* img_collectible = mlx_texture_to_image(mlx, text_collectible);
	
	mlx_delete_texture(text_wall);
	mlx_delete_texture(text_floor);
	mlx_delete_texture(text_player);
	mlx_delete_texture(text_exit);
	mlx_delete_texture(text_collectible);
	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->length)
		{
			if (map->map[x][y] == '1')
				mlx_image_to_window(mlx, img_wall, y * 64, x * 64);
			else if (map->map[x][y] == 'P')
				mlx_image_to_window(mlx, img_player, y * 64, x * 64);
			else if (map->map[x][y] == '0')
				mlx_image_to_window(mlx, img_floor, y * 64, x * 64);
			else if (map->map[x][y] == 'E')
				mlx_image_to_window(mlx, img_exit, y * 64, x * 64);
			else if (map->map[x][y] == 'C')
				mlx_image_to_window(mlx, img_collectible, y * 64, x * 64);
			y++;
		}
		x++;
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}


int	main(int argc, char **argv)
{
	char	**map;
	t_map	*tmap;

	argc = 0;
	map = read_map(argv[1]);
	tmap = init_map(map);
	if (parse_map(tmap) == -1)
		return (ft_putstr_fd("Error, invalid map\n", 2), 0);
	if (so_long(tmap) == -1)
		return (EXIT_FAILURE);
	return (0);
}