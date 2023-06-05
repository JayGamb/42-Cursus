/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:34:50 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/06/05 19:19:08 by jgamboa-         ###   ########.fr       */
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
	char	*temp_line;
	char	*line;
	char	*temp;
	
	map->r = ft_fcountlines(map->name);
	map->fd = open(map->name);
	if (map->fd < 0)
		ft_free_printerr(FOPEN_ERR, map, errno);
	while (get_next_line(map->fd) != NULL)
	{
		temp = get_next_line(map->fd);
		temp_line = ft_strjoin(ft_)
		ft_strlcpy(temp)
	}
}


int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	(void)argc;
	
	/* ft_check_args(argc, argv, ); */
	ft_printf("nb lines : %d\n", ft_fcountlines(argv[1]));

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	if (mlx_win == 0)
		return (1);
	mlx_loop(mlx);
	return (0);
}
