/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:38:10 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/10/02 15:55:02 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* size_t	ft_fcountlines(char *filename)
{
  int fd;
    char ch;
    int count = 0;
    ssize_t read_size;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Erreur d'ouverture du fichier");
        return -1;
    }

    while ((read_size = read(fd, &ch, 1)) > 0) {
        if (ch == '\n') {
            count++;
        }
    }

    if (read_size == -1) {
        perror("Erreur de lecture du fichier");
        close(fd);
        return -1;
    }

    close(fd);
	printf("%d\n", count);
    return count;
} */

size_t	ft_fcountlines(char *filename)
{
	int		file_fd;
	int		lines;
	char	*line;

	file_fd = open(filename, O_RDONLY, 0777);
	if (file_fd < 0)
		return (-1);
	lines = 0;
	while ((line = get_next_line(file_fd)) != NULL)
	{
		lines++;
		free(line);
	}
	close(file_fd);
	return (lines);
}

void	ft_get_map(t_game *game)
{
	char	*line;
	int	y;

	game->map.size[0] = ft_fcountlines(game->map.name);
	if (game->map.size[0] < 3)
		ft_printerror(MAP_ERR, 1);
	game->map.fd = open(game->map.name, O_RDONLY);
	if (game->map.fd < 0)
		ft_printerror(FOPEN_ERR, 1);
	game->map.map = (char **)malloc(game->map.size[0] * sizeof(char *) + 1);
	if (!game->map.map)
		ft_printerror(MALLOC_ERR, 1);
	y = 0;
	while (y < game->map.size[0])
	{
		line = get_next_line(game->map.fd);
		game->map.map[y] = ft_strdup(line);
		ft_delchar(game->map.map[y], '\n');
		free(line);
		y++;
	}
	game->map.map[y] = 0;
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
	int c;

	if (ft_check_ncolumn(game) < 0)
		ft_free_elements(1, MAP_ERR, game);
	if (ft_check_walls(game) < 0)
		ft_free_elements(1, MAP_ERR, game);
	if (ft_init_visited(game) < 0)
		ft_free_elements(1, MALLOC_ERR, game);
	if (game->map.player != 1 || game->map.exit != 1)
	{
		if (game->map.player != 1)
			ft_free_elements(1, ELEMENTS_ERR, game);
	}
	c = ft_navigate(game);
	if (game->map.collectable != c)
		ft_free_elements(1, COLLECTABLE_ERR, game);
	if (game->map.exit != 1 || game->map.collectable < 1)
		ft_free_elements(1, ELEMENTS_ERR, game);
	return (0);
}