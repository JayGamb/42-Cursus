/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:35:02 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/09/28 18:46:59 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (exit_code == 1)
	{
		ft_clean_map(&game->map);
		ft_printerror(err_message, exit_code);
	}
	if (exit_code == 2)
	{
		free(game->map.map);
		free(game->queue.first);
		ft_printerror(err_message, exit_code);
	}
}
