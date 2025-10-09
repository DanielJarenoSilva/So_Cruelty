/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:41:31 by djareno           #+#    #+#             */
/*   Updated: 2025/10/09 15:44:28 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libraries/MLX42/include/MLX42/MLX42.h"
# include "libraries/libft/libft.h"
# include <stdlib.h>

typedef struct map
{
	int				cnt_p;
	int				cnt_e;
	int				cnt_c;
	char			**map;
	int				length;
	int				height;
	int				player_in_exit;
	int				collectibes_collected;
	int				cont_moves;
}					t_map;
typedef struct textures
{
	mlx_image_t		*img_wall;
	mlx_image_t		*img_collect;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_player;
	mlx_image_t		*img_exit;
}					t_textures;
typedef struct player
{
	int				x;
	int				y;
}					t_player;
typedef struct game
{
	t_map			*map;
	t_textures		*textures;
	mlx_t			*mlx;
}					t_game;
char		**read_map(char	*map);
int			parse_map(t_map	*map);
t_map		*init_map(char **map);
int			check_size(t_map *map);
int			check_reacheable(t_map *map);
t_player	*find_player(t_map *map, char **copy);
#endif