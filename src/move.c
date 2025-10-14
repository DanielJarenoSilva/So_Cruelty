/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:16:04 by djareno           #+#    #+#             */
/*   Updated: 2025/10/14 15:13:55 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_exit(t_game *game, int mx, int my, t_player *p)
{
	game->map->map[p->x + mx][p->y + my] = 'P';
	game->map->map[p->x][p->y] = '0';
	game->map->player_in_exit = 1;
	game->map->cont_moves++;
	mlx_image_to_window(game->mlx, game->txt->img_floor, p->y * 64, p->x * 64);
	if (game->map->collectibes_collected == game->map->cnt_c)
		mlx_close_window(game->mlx);
}

void	move_collectible(t_game *g, int mx, int my, t_player *p)
{
	g->map->cont_moves++;
	g->map->collectibes_collected++;
	g->map->map[p->x + mx][p->y + my] = 'P';
	g->map->map[p->x][p->y] = '0';
	mlx_image_to_window(g->mlx, g->txt->img_floor, p->y * 64, p->x * 64);
	if (g->map->player_in_exit == 1)
	{
		g->map->map[p->x][p->y] = 'E';
		mlx_image_to_window(g->mlx, g->txt->img_exit, p->y * 64, p->x * 64);
	}
}

void	move(t_game *g, int mx, int my)
{
	t_player	*p;

	p = find_player(g->map, g->map->map);
	if (g->map->map[p->x + mx][p->y + my] == '0')
	{
		g->map->cont_moves++;
		g->map->map[p->x + mx][p->y + my] = 'P';
		g->map->map[p->x][p->y] = '0';
		mlx_image_to_window(g->mlx, g->txt->img_floor, p->y * 64, p->x * 64);
		if (g->map->player_in_exit == 1)
		{
			mlx_image_to_window(g->mlx, g->txt->img_exit, p->y * 64, p->x * 64);
			g->map->map[p->x][p->y] = 'E';
		}
	}
	else if (g->map->map[p->x + mx][p->y + my] == 'C')
	{
		move_collectible(g, mx, my, p);
	}
	g->map->player_in_exit = 0;
	if (g->map->map[p->x + mx][p->y + my] == 'E')
		move_exit(g, mx, my, p);
	free (p);
}

void	print_player(t_game *game)
{
	t_player	*p;

	p = find_player(game->map, game->map->map);
	mlx_image_to_window(game->mlx, game->txt->img_player, p->y * 64, p->x * 64);
	free (p);
}

void	key_hook_moves(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		move(game, -1, 0);
		ft_printf("%d\n", game->map->cont_moves);
		print_player(game);
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		move(game, 1, 0);
		ft_printf("%d\n", game->map->cont_moves);
		print_player(game);
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		move(game, 0, 1);
		ft_printf("%d\n", game->map->cont_moves);
		print_player(game);
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		move(game, 0, -1);
		ft_printf("%d\n", game->map->cont_moves);
		print_player(game);
	}
}
