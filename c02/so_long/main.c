/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:34:50 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/10/16 16:34:42 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_navigate(t_game *game)
{
	t_element	*current;
	int			reached;

	reached = 0;
	if (ft_enqueue(&game->queue, game->map.p) < 0)
		ft_printerr("enqueue ft_enqueue error", 2);
	current = game->queue.first;
	while (current)
	{
		ft_explore_neighbors(game, current->position);
		if (ft_iscollectable(
				game->map.map[current->position.y][current->position.x]))
			reached++;
		current = current->next;
	}
	return (reached);
}

int	ft_init_game(t_game *game)
{
	int		var[4];
	void	*space_ptr;

	var[0] = -1;
	space_ptr = mlx_xpm_file_to_image(game->vars.mlx, "./images/SPACE.xpm", \
	&var[2], &var[3]);
	while (++var[0] < game->map.size[0])
	{
		var[1] = -1;
		while (++var[1] < game->map.size[1])
		{
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, space_ptr, \
			var[1] * var[2], var[0] * var[3]);
			game->image = ft_get_image(game->map.map[var[0]][var[1]], \
			game->vars.mlx, game);
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
			game->image.xpm_ptr, var[1] * game->image.img_width, \
			var[0] * game->image.img_height);
			mlx_destroy_image(game->vars.mlx, game->image.xpm_ptr);
		}
	}
	mlx_destroy_image(game->vars.mlx, space_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = (t_map){0};
	game.queue = (t_queue){0};
	game.steps = 0;
	ft_check_args(argc, argv, &game);
	ft_get_map(&game);
	ft_check_map(&game);
	game.vars.mlx = mlx_init();
	if (!game.vars.mlx)
		exit(1);
	game.vars.win = mlx_new_window(game.vars.mlx, game.map.size[1] * 50, \
	game.map.size[0] * 50, "so_long");
	if (!game.vars.win)
		exit(1);
	ft_init_game(&game);
	mlx_hook(game.vars.win, 17, 0, ft_close, &game);
	mlx_hook(game.vars.win, 2, 0, ft_handle_key, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}
