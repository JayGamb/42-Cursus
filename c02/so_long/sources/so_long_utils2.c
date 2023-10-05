/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:36:36 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/10/05 20:51:17 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_accessible(t_game *game)
{
	int		xy[4];
	char	**map;

	map = game->map.map;
	xy[2] = -1;
	while (++xy[2] < game->map.size[0])
	{
		xy[3] = -1;
		while (++xy[3] < game->map.size[1])
		{
			if (map[xy[2]][xy[3]] == EXIT)
			{
				if ((xy[2] - 1 >= 0 && (map[xy[2] - 1][xy[3]] == '0' || \
				map[xy[2] - 1][xy[3]] == 'C')) || (xy[2] + 1 < \
				game->map.size[0] && (map[xy[2] + 1][xy[3]] == '0' || \
				map[xy[2] + 1][xy[3]] == 'C')) || (xy[3] - 1 >= 0 && \
				(map[xy[2]][xy[3] - 1] == '0' || map[xy[2]][xy[3] - 1] == \
				'C')) || (xy[3] + 1 < game->map.size[1] && \
				(map[xy[2]][xy[3] + 1] == '0' || map[xy[2]][xy[3] + 1] == 'C')))
					return (1);
				return (0);
			}
		}
	}
	return (0);
}

int	init_row(t_game *game, int i)
{
	int		j;
	t_map	*map;

	map = &game->map;
	j = 0;
	while (j < map->size[1])
	{
		game->map.visited[i][j] = false;
		if (ft_isplayer(game->map.map[i][j]))
		{
			map->p.x = j;
			map->p.y = i;
			map->player++;
			game->map.visited[i][j] = true;
		}
		if (ft_iscollectable(game->map.map[i][j]))
			map->collectable++;
		if (ft_isexit(game->map.map[i][j]))
			map->exit++;
		j++;
	}
	return (0);
}

int	ft_init_visited(t_game *game)
{
	int		i;
	t_map	*map;

	map = &game->map;
	game->map.visited = malloc(sizeof(bool *) * map->size[0]);
	if (!game->map.visited)
		return (-1);
	i = 0;
	while (i < map->size[0])
	{
		game->map.visited[i] = malloc(sizeof(bool) * map->size[1]);
		if (!game->map.visited[i])
			return (-1);
		init_row(game, i);
		i++;
	}
	return (0);
}
