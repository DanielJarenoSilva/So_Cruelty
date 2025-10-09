/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:09:05 by djareno           #+#    #+#             */
/*   Updated: 2025/10/09 15:46:29 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_game *game)
{
	t_player	*player;

	player = find_player(game->map, game->map->map);
	if (game->map->map[player->x - 1][player->y] == '0')
	{
		game->map->map[player->x - 1][player->y] = 'P';
		game->map->map[player->x][player->y] = '0';
		if (game->map->player_in_exit == 1)
			game->map->map[player->x][player->y] = 'E';
	}
	else if (game->map->map[player->x - 1][player->y] == 'C')
	{
		game->map->collectibes_collected++;
		game->map->map[player->x - 1][player->y] = 'P';
		game->map->map[player->x][player->y] = '0';
		if (game->map->player_in_exit == 1)
			game->map->map[player->x][player->y] = 'E';
	}
	game->map->player_in_exit = 0;
	if (game->map->map[player->x - 1][player->y] == 'E')
	{
		game->map->map[player->x - 1][player->y] = 'P';
		game->map->map[player->x][player->y] = '0';
		game->map->player_in_exit = 1;
		if (game->map->collectibes_collected == game->map->cnt_c)
			mlx_close_window(game->mlx);
	}
}

void	down(t_game *game)
{
	t_player	*player;

	player = find_player(game->map, game->map->map);
	if (game->map->map[player->x + 1][player->y] == '0')
	{
		game->map->map[player->x + 1][player->y] = 'P';
		game->map->map[player->x][player->y] = '0';
		if (game->map->player_in_exit == 1)
			game->map->map[player->x][player->y] = 'E';
	}
	else if (game->map->map[player->x + 1][player->y] == 'C')
	{
		game->map->collectibes_collected++;
		game->map->map[player->x + 1][player->y] = 'P';
		game->map->map[player->x][player->y] = '0';
		if (game->map->player_in_exit == 1)
			game->map->map[player->x][player->y] = 'E';
	}
	game->map->player_in_exit = 0;
	if (game->map->map[player->x + 1][player->y] == 'E')
	{
		game->map->map[player->x + 1][player->y] = 'P';
		game->map->map[player->x][player->y] = '0';
		game->map->player_in_exit = 1;
		if (game->map->collectibes_collected == game->map->cnt_c)
			mlx_close_window(game->mlx);
	}
}

void	right(t_game *game)
{
	t_player	*player;

	player = find_player(game->map, game->map->map);
	if (game->map->map[player->x][player->y + 1] == '0')
	{
		game->map->map[player->x][player->y + 1] = 'P';
		game->map->map[player->x][player->y] = '0';
		if (game->map->player_in_exit == 1)
			game->map->map[player->x][player->y] = 'E';
	}
	else if (game->map->map[player->x][player->y + 1] == 'C')
	{
		game->map->collectibes_collected++;
		game->map->map[player->x][player->y + 1] = 'P';
		game->map->map[player->x][player->y] = '0';
		if (game->map->player_in_exit == 1)
			game->map->map[player->x][player->y] = 'E';
	}
	game->map->player_in_exit = 0;
	if (game->map->map[player->x][player->y + 1] == 'E')
	{
		game->map->map[player->x][player->y + 1] = 'P';
		game->map->map[player->x][player->y] = '0';
		game->map->player_in_exit = 1;
		if (game->map->collectibes_collected == game->map->cnt_c)
			mlx_close_window(game->mlx);
	}
}

void	left(t_game *game)
{
	t_player	*player;

	player = find_player(game->map, game->map->map);
	if (game->map->map[player->x][player->y - 1] == '0')
	{
		game->map->map[player->x][player->y - 1] = 'P';
		game->map->map[player->x][player->y] = '0';
		if (game->map->player_in_exit == 1)
			game->map->map[player->x][player->y] = 'E';
	}
	else if (game->map->map[player->x][player->y - 1] == 'C')
	{
		game->map->collectibes_collected++;
		game->map->map[player->x][player->y - 1] = 'P';
		game->map->map[player->x][player->y] = '0';
		if (game->map->player_in_exit == 1)
			game->map->map[player->x][player->y] = 'E';
	}
	game->map->player_in_exit = 0;
	if (game->map->map[player->x][player->y - 1] == 'E')
	{
		game->map->map[player->x][player->y - 1] = 'P';
		game->map->map[player->x][player->y] = '0';
		game->map->player_in_exit = 1;
		if (game->map->collectibes_collected == game->map->cnt_c)
			mlx_close_window(game->mlx);
	}
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
			if (map->map[x][y] == '0')
				mlx_image_to_window(mlx, textures->img_floor, y * 64, x * 64);
			y++;
		}
		x++;
	}
}

void	put_textures(t_map *map, t_textures *textures, mlx_t *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->length)
		{
			if (map->map[x][y] == '1')
				mlx_image_to_window(mlx, textures->img_wall, y * 64, x * 64);
			else if (map->map[x][y] == 'E')
				mlx_image_to_window(mlx, textures->img_exit, y * 64, x * 64);
			else if (map->map[x][y] == 'C')
				mlx_image_to_window(mlx, textures->img_collect, y * 64, x * 64);
			else if (map->map[x][y] == 'P')
				mlx_image_to_window(mlx, textures->img_player, y * 64, x * 64);
			y++;
		}
		x++;
	}
}

void	frame_funcs(t_map *map, t_textures *textures, mlx_t *mlx)
{
	put_background(map, textures, mlx);
	put_textures(map, textures, mlx);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
	}
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		up(game);
		game->map->cont_moves++;
		ft_printf("%d\n", game->map->cont_moves);
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		down(game);
		game->map->cont_moves++;
		ft_printf("%d\n", game->map->cont_moves);
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		right(game);
		game->map->cont_moves++;
		ft_printf("%d\n", game->map->cont_moves);
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		left(game);
		game->map->cont_moves++;
		ft_printf("%d\n", game->map->cont_moves);
	}
}

void	frame_funcs_wrapper(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	frame_funcs(game->map, game->textures, game->mlx);
}

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
	text_player = mlx_load_png("textures/player.png");
	text_collectible = mlx_load_png("textures/collectible.png");
	textures->img_wall = mlx_texture_to_image(mlx, text_wall);
	textures->img_floor = mlx_texture_to_image(mlx, text_floor);
	textures->img_exit = mlx_texture_to_image(mlx, text_exit);
	textures->img_player = mlx_texture_to_image(mlx, text_player);
	textures->img_collect = mlx_texture_to_image(mlx, text_collectible);
	mlx_delete_texture(text_wall);
	mlx_delete_texture(text_floor);
	mlx_delete_texture(text_player);
	mlx_delete_texture(text_exit);
	mlx_delete_texture(text_collectible);
}

int	so_long(t_map *map)
{
	mlx_t		*mlx;
	t_textures	*textures;
	t_game		*game;

	mlx = mlx_init(map->length * 64, map->height * 64, "so cruel", true);
	if (!mlx)
		return (-1);
	textures = malloc(sizeof(t_textures));
	set_textures(textures, mlx);
	game = malloc(sizeof(t_game));
	game->map = map;
	game->mlx = mlx;
	game->textures = textures;
	mlx_loop_hook(mlx, frame_funcs_wrapper, game);
	mlx_key_hook(mlx, key_hook, game);
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