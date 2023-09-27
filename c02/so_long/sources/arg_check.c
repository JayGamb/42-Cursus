/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:35:02 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/09/20 16:34:07 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ft_check_args(int argc, char **argv, t_map *map, t_queue *queue)
// {
// 	int	ext_idx;

// 	if (argc < 2)
// 	{
// 		free(map);
// 		free(queue);
// 		exit(ft_printerr(FEW_ARGS_ERR, 1));
// 	}
// 	if (argc > 2)
// 	{
// 		free(map);
// 		free(queue);
// 		exit(ft_printerr(MANY_ARGS_ERR, 1));
// 	}
// 	ext_idx = ft_strlen(argv[1]) - 4;
// 	if (!ft_strnstr(&argv[1][ext_idx], EXPECTED_EXTENSION, 4))
// 	{
// 		free(map);
// 		free(queue);
// 		exit(ft_printerr(EXTENSION_ERR, 1));
// 	}
// 	map->name = argv[1];
// 	return (0);
// }

// void	ft_check_initalloc(t_map *map, t_queue *queue)
// {
// 	if (!map && queue)
// 	{
// 		free(queue);
// 		ft_printerr(MALLOC_ERR,INIT_MALLOC_ERR);
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (!queue && map)
// 	{
// 		free(map);
// 		ft_printerr(MALLOC_ERR,INIT_MALLOC_ERR);
// 		exit(EXIT_FAILURE);
// 	}
// }

// void	ft_free_elements(int exit_code, char *err_message, t_map *map, t_queue *queue)
// {
// 	if (exit_code == 3)
// 	{
// 		free(map);
// 		free(queue);
// 		ft_printerror(err_message, exit_code);
// 	}
// 	if (exit_code == 4)
// 	{
// 		ft_clean_map(map);
// 		free(queue);
// 		ft_printerror(err_message, exit_code);
// 	}
// 	if (exit_code == 5)
// 	{
// 		ft_clean_map(map);
// 		ft_clean_queue(queue);
// 		ft_printerror(err_message, exit_code);
// 	}

// }

int	ft_check_args(int argc, char **argv, t_game *game)
{
	int	ext_idx;

	ext_idx = ft_strlen(argv[1]) - 4;
	if (argc < 2)
		ft_printerr("err_message", 1);
//		ft_free_elements(1, FEW_ARGS_ERR, &game->map, &game->queue);
	if (argc > 2)
//		ft_free_elements(1, MANY_ARGS_ERR, &game->map, &game->queue);
	if (!ft_strnstr(&argv[1][ext_idx], EXPECTED_EXTENSION, 4))
		ft_printerr("err_message", 1);
//		ft_free_elements(1, EXTENSION_ERR, &game->map, &game->queue);
	game->map.name = argv[1];
	return (0);
}

/* void	ft_check_initalloc(t_game *game)
{
	if (!game->map && game->queue)
	{
		free(&game->queue);
		ft_printerr(MALLOC_ERR,INIT_MALLOC_ERR);
		exit(EXIT_FAILURE);
	}
	else if (!game->queue && game->map)
	{
		free(&game->map);
		ft_printerr(MALLOC_ERR,INIT_MALLOC_ERR);
		exit(EXIT_FAILURE);
	}
} */

void	ft_free_elements(int exit_code, char *err_message,\
t_game *game)
{
/* 	if (exit_code == 1)
	{
		free(map);
		free(queue);
		ft_printerr(err_message, exit_code);
	}
	if (exit_code == 3)
	{
		free(map);
		free(queue);
		ft_printerr(err_message, exit_code);
	}
	if (exit_code == 4)
	{
		ft_clean_map(map);
		free(queue);
		ft_printerr(err_message, exit_code);
	} */
	if (exit_code == 5)
	{
		ft_clean_map(&game->map);
		ft_clean_queue(&game->queue);
		ft_printerr(err_message, exit_code);
	}
}
