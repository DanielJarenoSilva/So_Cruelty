/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nowitspersonal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:13:43 by djareno           #+#    #+#             */
/*   Updated: 2025/10/21 10:37:42 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_textures_nowitspersonal(t_textures *textures, mlx_t *mlx)
{
	mlx_texture_t	*text_infierno;
	mlx_texture_t	*text_jorker;
	mlx_texture_t	*text_musk;
	mlx_texture_t	*text_crujiente;
	mlx_texture_t	*text_umberto;

	text_infierno = mlx_load_png("textures/wallI.png");
	text_jorker = mlx_load_png("textures/jorker.png");
	text_musk = mlx_load_png("textures/muskface.png");
	text_crujiente = mlx_load_png("textures/crujiente.png");
	text_umberto = mlx_load_png("textures/umberto.png");
	textures->img_infierno = mlx_texture_to_image(mlx, text_infierno);
	textures->img_jorker = mlx_texture_to_image(mlx, text_jorker);
	textures->img_musk = mlx_texture_to_image(mlx, text_musk);
	textures->img_crujiente = mlx_texture_to_image(mlx, text_crujiente);
	textures->img_umberto = mlx_texture_to_image(mlx, text_umberto);
	mlx_delete_texture(text_infierno);
	mlx_delete_texture(text_jorker);
	mlx_delete_texture(text_musk);
	mlx_delete_texture(text_crujiente);
	mlx_delete_texture(text_umberto);
}

void	gotham_asyllum(t_game *g, int x, int y)
{
	if (g->map->map[x + 1][y] == 'E')
	{
		mlx_image_to_window(g->mlx, g->txt->img_jorker, 1 * 64, 1 * 64);
		print_player(g, g->txt->img_player);
	}
	else if (g->map->cont_moves % 7 == 0)
	{
		print_player(g, g->txt->img_musk);
	}
	else if (g->map->cont_moves % 13 == 0)
	{
		mlx_image_to_window(g->mlx, g->txt->img_crujiente, x * 64, y * 64);
		print_player(g, g->txt->img_player);
	}
	else if (g->map->cont_moves == 69)
	{
		mlx_image_to_window(g->mlx, g->txt->img_crujiente, x * 64, y * 64);
		print_player(g, g->txt->img_umberto);
	}
	else
		print_player(g, g->txt->img_player);
}

void	put_infierno(t_game *g, int x, int y)
{
	if ((x == 0 && y == 0) || (x == 0 && y == g->map->length -1))
		mlx_image_to_window(g->mlx, g->txt->img_infierno, y * 64, x * 64);
	else if ((x == g->map->height - 1 && y == 0)
		|| (x == g->map->height - 1 && y == g->map->length - 1))
		mlx_image_to_window(g->mlx, g->txt->img_infierno, y * 64, x * 64);
	else
		mlx_image_to_window(g->mlx, g->txt->img_wall, y * 64, x * 64);
}
