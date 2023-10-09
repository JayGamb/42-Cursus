/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:35:02 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/10/09 14:16:37 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_args(int argc, char **argv, t_game *game)
{
	int	ext_idx;

	if (argc < 2)
		ft_free_elements(1, FEW_ARGS_ERR, game);
	if (argc > 2)
		ft_free_elements(1, MANY_ARGS_ERR, game);
	ext_idx = ft_strlen(argv[1]) - 4;
	if (!ft_strnstr(&argv[1][ext_idx], EXPECTED_EXTENSION, 4))
		ft_free_elements(1, EXTENSION_ERR, game);
	game->map.name = argv[1];
	return (0);
}

void	ft_free_elements(int exit_code, char *message, \
	t_game *game)
{
	if (exit_code == 0)
	{
		ft_clean_map(&game->map);
		ft_printf("%s\n", message);
		mlx_destroy_window(game->vars.mlx, game->vars.win);
	}
	if (exit_code == 1)
	{
		ft_clean_map(&game->map);
		ft_printerror(message, exit_code);
	}
}
