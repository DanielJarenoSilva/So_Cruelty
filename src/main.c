/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:09:05 by djareno           #+#    #+#             */
/*   Updated: 2025/10/20 10:52:37 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
	}
	else
		key_hook_moves(keydata, game);
}

void	free_structs(t_game *game)
{
	ft_free_matrix(game->map->map);
	free_textures (game->mlx, game->txt);
	free (game->map);
	free (game);
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
	game->txt = textures;
	frame_funcs(game);
	mlx_key_hook(mlx, key_hook, game);
	mlx_loop(mlx);
	free_structs(game);
	mlx_terminate(mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_map	*tmap;

	if (argc != 2)
		return (ft_putstr_fd("Error\ninvalid arguments\n", 2), 0);
	map = read_map(argv[1]);
	if (!map)
		return (ft_putstr_fd("Error\ninvalid map\n", 2), 0);
	tmap = init_map(map);
	if (parse_map(tmap) == -1)
	{
		ft_free_matrix(map);
		free (tmap);
		return (ft_putstr_fd("Error\ninvalid map\n", 2), 0);
	}
	if (so_long(tmap) == -1)
		return (EXIT_FAILURE);
	return (0);
}
