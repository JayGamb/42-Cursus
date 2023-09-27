/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:38:10 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/09/20 16:34:50 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_fcountlines(char *filename)
{
	int	file_fd;
	int	lines;

	file_fd = open(filename, O_RDONLY, 0777);
	if (file_fd < 0)
		return (-1);
	lines = 0;
	while (get_next_line(file_fd) != NULL)
	{
		lines++;
	}
	close(file_fd);
	return (lines);
}

// void	ft_get_map(t_game *game)
// {
// 	char	*line;
// 	int		y;

// 	map->size[0] = ft_fcountlines(game->map);
// 	if (map->size[0] < 3)
// 		ft_free_elements(3, MAP_ERR, map, queue);
// 	map->fd = open(map->name, O_RDONLY);
// 	if (map->fd < 0)
// 		ft_free_elements(3, FOPEN_ERR, map, queue);
// 	map->map = (char **)malloc(map->size[0] * sizeof(char *) + 1);
// 	if (!map->map)
// 		ft_free_elements(3, MALLOC_ERR, map, queue);
// 	y = 0;
// 	while (y < map->size[0])
// 	{
// 		line = get_next_line(map->fd);
// 		map->map[y] = ft_strdup(line);
// 		ft_delchar(map->map[y], '\n');
// 		y++;
// 	}
// 	map->map[y] = 0;
// 	free(line);
// 	close(map->fd);
// }
// /* 	ft_printf("number of lines: %d\n", map->size[0]); */
// /* 	printf("DONE!\n"); */

// int	ft_check_ncolumn(t_map *map)
// {
// 	int		y;
// 	size_t	column;

// 	y = 0;
// 	column = ft_strlen(map->map[0]);
// 	while (map->map[y])
// 	{
// 		if (column != ft_strlen(map->map[y]))
// 			return (-1);
// 		y++;
// 	}
// 	map->size[1] = column;
// 	return (map->size[1]);
// }
// /* 	ft_printf("number of columns: %d\n", map->size[1]); */

// int	ft_check_walls(t_map *map)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (map->map[y])
// 	{
// 		if (y == 0 || y == map->size[0] - 1)
// 		{
// 			x = 0;
// 			while (map->map[y][x])
// 			{
// 				if (map->map[y][x] != WALL)
// 					return (-1);
// 				x++;
// 			}
// 		}
// 		else
// 		{
// 			if (map->map[y][0] != WALL || map->map[y][map->size[1] - 1] != WALL)
// 				return (-1);
// 		}
// 		y++;
// 	}
// 	return (0);
// }

// int	ft_check_map(t_map *map, t_queue *queue)
// {
// 	if (ft_check_ncolumn(map) < 0)
// 		ft_free_elements(4, MAP_ERR, map, queue);
// 	if (ft_check_walls(map) < 0)
// 		ft_free_elements(4, MAP_ERR, map, queue);
// 	if (ft_init_visited(map) < 0)
// 		ft_free_elements(4, MALLOC_ERR, map, queue);
// 	if (map->player != 1 || map->exit != 1)
// 	{
// 		if (map->player != 1)
// 		ft_free_elements(4, ELEMENTS_ERR, map, queue);
// 	}
// 	ft_navigate(map, queue);
// 	if (map->collectable != 0)
// 		ft_free_elements(5, COLLECTABLE_ERR, map, queue);
// 	if (map->exit != 1)
// 		ft_free_elements(5, ELEMENTS_ERR, map, queue);
// 	return (0);
// }


void	ft_get_map(t_game *game)
{
	char	*line;
	int	y;

	game->map.size[0] = ft_fcountlines(game->map.name);
	if (game->map.size[0] < 3)
		ft_free_elements(3, MAP_ERR, game);
	game->map.fd = open(game->map.name, O_RDONLY);
	if (game->map.fd < 0)
		ft_free_elements(3, FOPEN_ERR, game);

	game->map.map = (char **)malloc(game->map.size[0] * sizeof(char *) + 1);
	if (!game->map.map)
		ft_free_elements(3, MALLOC_ERR, game);

	y = 0;
	while (y < game->map.size[0])
	{
		line = get_next_line(game->map.fd);
		game->map.map[y] = ft_strdup(line);
		ft_delchar(game->map.map[y], '\n');
		y++;
	}
	game->map.map[y] = 0;
	free(line);
	close(game->map.fd);
}

int	ft_check_ncolumn(t_game *game)
{
	int		y;
	size_t	column;

	y = 0;
	column = ft_strlen(game->map.map[0]);
	while (game->map.map[y])
	{
		if (column != ft_strlen(game->map.map[y]))
			return (-1);
		y++;
	}
	game->map.size[1] = column;
	return (game->map.size[1]);
}

int	ft_check_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		if (y == 0 || y == game->map.size[0] - 1)
		{
			x = 0;
			while (game->map.map[y][x])
			{
				if (game->map.map[y][x] != WALL)
					return (-1);
				x++;
			}
		}
		else
		{
			if (game->map.map[y][0] != WALL ||
				game->map.map[y][game->map.size[1] - 1] != WALL)
				return (-1);
		}
		y++;
	}
	return (0);
}

int	ft_check_map(t_game *game)
{
	if (ft_check_ncolumn(game) < 0)
		ft_free_elements(4, MAP_ERR, game);
	if (ft_check_walls(game) < 0)
		ft_free_elements(4, MAP_ERR, game);
	if (ft_init_visited(game) < 0) // If the function accepts a pointer
		ft_free_elements(4, MALLOC_ERR, game);
	if (game->map.player != 1 || game->map.exit != 1)
	{
		if (game->map.player != 1)
			ft_free_elements(4, ELEMENTS_ERR, game);
	}
	ft_navigate(game);
	if (game->map.collectable != 0)
		ft_free_elements(5, COLLECTABLE_ERR, game);
	if (game->map.exit != 1)
		ft_free_elements(5, ELEMENTS_ERR, game);
	return (0);
}