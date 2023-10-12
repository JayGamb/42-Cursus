/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:36:36 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/10/09 13:53:05 by jgamboa-         ###   ########.fr       */
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
				map[xy[2] - 1][xy[3]] == 'C' || map[xy[2] - 1][xy[3]] == 'P')) \
				|| (xy[2] + 1 < game->map.size[0] && (map[xy[2] + 1][xy[3]] == \
				'0' || map[xy[2] + 1][xy[3]] == 'C' || map[xy[2] + 1][xy[3]] == \
				'P')) || (xy[3] - 1 >= 0 && (map[xy[2]][xy[3] - 1] == '0' || \
				map[xy[2]][xy[3] - 1] == 'C' || map[xy[2]][xy[3] - 1] == 'P')) \
				|| (xy[3] + 1 < game->map.size[1] && (map[xy[2]][xy[3] + 1] == '0' \
				|| map[xy[2]][xy[3] + 1] == 'C' || map[xy[2]][xy[3] + 1] == 'P')))
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

int	ft_check_mapbody(t_game *game)
{
	char	**map;
	int		i;
	int		j;
	int		isvalid;

	map = game->map.map;
	i = 0;
	isvalid = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == WALL || map[i][j] == SPACE || map[i][j] == \
			COLLECTABLE || map[i][j] == EXIT || map[i][j] == PLAYER)
				isvalid = 0;
			else
				isvalid = -1;
			j++;
		}
		i++;
	}
	return (isvalid);
}
