/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:30:06 by djareno           #+#    #+#             */
/*   Updated: 2025/10/21 10:37:45 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_textures(t_textures *textures, mlx_t *mlx)
{
	mlx_texture_t	*text_wall;
	mlx_texture_t	*text_floor;
	mlx_texture_t	*text_exit;
	mlx_texture_t	*text_player;
	mlx_texture_t	*text_collectible;

	text_wall = mlx_load_png("textures/wall.png");
	text_exit = mlx_load_png("textures/exit.png");
	text_floor = mlx_load_png("textures/floor.png");
	text_player = mlx_load_png("textures/gorbino1.png");
	text_collectible = mlx_load_png("textures/collectible.png");
	textures->img_wall = mlx_texture_to_image(mlx, text_wall);
	textures->img_floor = mlx_texture_to_image(mlx, text_floor);
	textures->img_exit = mlx_texture_to_image(mlx, text_exit);
	textures->img_player = mlx_texture_to_image(mlx, text_player);
	textures->img_col = mlx_texture_to_image(mlx, text_collectible);
	mlx_delete_texture(text_wall);
	mlx_delete_texture(text_floor);
	mlx_delete_texture(text_player);
	mlx_delete_texture(text_exit);
	mlx_delete_texture(text_collectible);
	set_textures_nowitspersonal(textures, mlx);
}

void	put_background(t_map *map, t_textures *textures, mlx_t *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->length)
		{
			if (map->map[x][y] == '0' || map->map[x][y] == 'E')
				mlx_image_to_window(mlx, textures->img_floor, y * 64, x * 64);
			y++;
		}
		x++;
	}
}

void	put_textures(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	while (x < g->map->height)
	{
		y = 0;
		while (y < g->map->length)
		{
			if (g->map->map[x][y] == '1')
				put_infierno(g, x, y);
			else if (g->map->map[x][y] == 'E')
				mlx_image_to_window(g->mlx, g->txt->img_exit, y * 64, x * 64);
			else if (g->map->map[x][y] == 'C')
				mlx_image_to_window(g->mlx, g->txt->img_col, y * 64, x * 64);
			else if (g->map->map[x][y] == 'P')
			{
				mlx_image_to_window(g->mlx, g->txt->img_floor, y * 64, x * 64);
				mlx_image_to_window(g->mlx, g->txt->img_player, y * 64, x * 64);
			}
			y++;
		}
		x++;
	}
}

void	frame_funcs(t_game *g)
{
	put_background(g->map, g->txt, g->mlx);
	put_textures(g);
}

void	frame_funcs_wrapper(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	frame_funcs(game);
}
