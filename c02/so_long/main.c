/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:34:50 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/06/12 15:31:14 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check args
// check extension fichier .ber |||| example map.ber \\ a.ber
// check la map si elle est rectangulaire

void	ft_free_printerr(char *message, t_map *map, int exit_code)
{
	free(map);
	ft_printerror(message, exit_code);
}

void	ft_printarray(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		ft_printf("%s\n", array[i]);
}

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

void	ft_check_args(int argc, char **argv, t_map *map)
{
	int	ext_idx;

	if (argc < 2)
		ft_printerror(FEW_ARGS_ERR, 1);
	if (argc > 2)
		ft_printerror(MANY_ARGS_ERR, 1);
	ext_idx = ft_strlen(argv[1]) - 4;
	if (!ft_strnstr(&argv[1][ext_idx], EXPECTED_EXTENSION, 4))
		ft_printerror(EXTENSION_ERR, 1);
	map->name = argv[1];
}

void	ft_get_map(t_map *map)
{
	char	*line;
	int	i;

	map->r = ft_fcountlines(map->name);
	map->map = (char **)malloc(map->r * sizeof(char*) + 1);
	if (!map->map)
		ft_printerror(MALLOC_ERR, errno);
	ft_printf("number of lines: %d\n", map->r);
	map->fd = open(map->name, O_RDONLY);
	if (map->fd < 0)
		ft_free_printerr(FOPEN_ERR, map, errno);
	i = 0;
	while (i < map->r)
	{
		line = get_next_line(map->fd);
		map->map[i] = ft_strdup(line);
		ft_delchar(map->map[i], '\n');
		i++;
	}
	map->map[i] = 0;
	free(line);
	close(map->fd);
	printf("DONE!\n");
}

int	ft_check_ncolumn(t_map *map)
{
	int	i;
	size_t	column;

	i = 0;
	column = ft_strlen(map->map[0]);
	while (map->map[i])
	{
		if (column != ft_strlen(map->map[i]))
			return (-1);
		i++;
	}
	map->c = column;
	return (map->c);
}

int	ft_check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		if (i == 0 || i == map->r - 1)
		{
			j = 0;
			while (map->map[i][j])
			{
				if (map->map[i][j] != WALL)
					return (-1);
				j++;
			}
		}
		else
		{
			if (map->map[i][0] != WALL || map->map[i][map->c - 1] != WALL)
				return (-1);
		}
		i++;
	}
	return (0);
}

/* int ft_check */



void ft_check_map(t_map *map)
{
	if (ft_check_ncolumn(map) < 0)
		ft_free_printerr("Error C", map, 1);
	if (ft_check_walls(map) < 0)
		ft_free_printerr("Errors with walls", map, 1);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_printerror(MALLOC_ERR, errno);
	ft_check_args(argc, argv, map);
	ft_get_map(map);
	ft_check_map(map);
	ft_printarray(map->map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	if (mlx_win == 0)
		return (1);
	mlx_loop(mlx);
	return (0);
}
