/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_exploration.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:12:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/10/13 16:37:35 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position	ft_check_north(t_game *game, t_position current)
{
	t_position	new_element;

	new_element.x = -1;
	new_element.y = -1;
	if ((current.y - 1 >= 0 && game->map.map[current.y - 1][current.x] != EXIT) \
	&& (current.y - 1 >= 0 && game->map.map[current.y - 1][current.x] != WALL))
	{
		if (game->map.visited[current.y - 1][current.x] == false)
		{
			game->map.visited[current.y - 1][current.x] = true;
			new_element.x = current.x;
			new_element.y = current.y - 1;
		}
	}
	return (new_element);
}

t_position	ft_check_south(t_game *game, t_position current)
{
	t_position	new_element;

	new_element.x = -1;
	new_element.y = -1;
	if ((current.y + 1 < game->map.size[0] && \
	game->map.map[current.y + 1][current.x] != EXIT) && (current.y + 1 < \
	game->map.size[0] && game->map.map[current.y + 1][current.x] != WALL))
	{
		if (game->map.visited[current.y + 1][current.x] == false)
		{
			game->map.visited[current.y + 1][current.x] = true;
			new_element.x = current.x;
			new_element.y = current.y + 1;
		}
	}
	return (new_element);
}

t_position	ft_check_east(t_game *game, t_position current)
{
	t_position	new_element;

	new_element.x = -1;
	new_element.y = -1;
	if ((current.x + 1 < game->map.size[1] && \
	game->map.map[current.y][current.x + 1] != EXIT) && (current.x + 1 < \
	game->map.size[1] && game->map.map[current.y][current.x + 1] != WALL))
	{
		if (game->map.visited[current.y][current.x + 1] == false)
		{
			game->map.visited[current.y][current.x + 1] = true;
			new_element.x = current.x + 1;
			new_element.y = current.y;
		}
	}
	return (new_element);
}

t_position	ft_check_west(t_game *game, t_position current)
{
	t_position	new_element;

	new_element.x = -1;
	new_element.y = -1;
	if ((current.x - 1 >= 0 && game->map.map[current.y][current.x - 1] != EXIT) \
	&& (current.x - 1 >= 0 && game->map.map[current.y][current.x - 1] != WALL))
	{
		if (game->map.visited[current.y][current.x - 1] == false)
		{
			game->map.visited[current.y][current.x - 1] = true;
			new_element.x = current.x - 1;
			new_element.y = current.y;
		}
	}
	return (new_element);
}

void	ft_explore_neighbors(t_game *game, t_position current)
{
	t_position	north;
	t_position	south;
	t_position	west;
	t_position	east;

	north = ft_check_north(game, current);
	south = ft_check_south(game, current);
	west = ft_check_west(game, current);
	east = ft_check_east(game, current);
	if (north.x != -1)
		ft_enqueue(&game->queue, north);
	if (east.x != -1)
		ft_enqueue(&game->queue, east);
	if (south.x != -1)
		ft_enqueue(&game->queue, south);
	if (west.x != -1)
		ft_enqueue(&game->queue, west);
}
