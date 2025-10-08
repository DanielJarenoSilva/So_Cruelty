/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:41:31 by djareno           #+#    #+#             */
/*   Updated: 2025/10/08 16:41:39 by djareno          ###   ########.fr       */
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
}					t_map;
char		**read_map(char	*map);
int			parse_map(t_map	*map);
t_map		*init_map(char **map);
int			check_size(t_map *map);
int			check_reacheable(t_map *map);
#endif