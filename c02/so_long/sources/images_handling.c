/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:15:31 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/10/09 15:31:40 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_walk(int step)
{
	if (step % 2 == 0)
		return ("./images/2Walk.xpm");
	else if (step % 3 == 0)
		return ("./images/3walk.xpm");
	else if (step % 4 == 0)
		return ("./images/4walk.xpm");
	else if (step % 5 == 0)
		return ("./images/5walk.xpm");
	else
		return ("./images/1walk.xpm");
}

t_image	ft_get_image(char element, void *mlx, t_game *game)
{
	t_image	image;

	if (element == WALL)
		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/Block_A_02.xpm", \
		&image.img_width, &image.img_height);
	if (element == SPACE)
		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/SPACE.xpm", \
		&image.img_width, &image.img_height);
	if (element == COLLECTABLE)
		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/ball.xpm", \
		&image.img_width, &image.img_height);
	if (element == EXIT)
		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", \
		&image.img_width, &image.img_height);
	if (element == PLAYER)
	{
		image.xpm_ptr = mlx_xpm_file_to_image(mlx, ft_walk(game->steps), \
		&image.img_width, &image.img_height);
	}
	return (image);
}

void	ft_update_player_position(int keycode, t_map *map, \
int *new_x, int *new_y)
{
	*new_x = map->p.x;
	*new_y = map->p.y;
	if (keycode == KEY_LEFT || keycode == KEY_A)
		*new_x = map->p.x - 1;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		*new_x = map->p.x + 1;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		*new_y = map->p.y + 1;
	else if (keycode == KEY_UP || keycode == KEY_W)
		*new_y = map->p.y - 1;
}

void	ft_handle_player_exit(t_game *game, int new_x, int new_y)
{
	t_map	*map;

	map = &(game->map);
	if (game->map.collectable == 0 && map->map[new_y][new_x] == EXIT)
	{
		map->map[map->p.y][map->p.x] = SPACE;
		map->map[new_y][new_x] = PLAYER;
		map->p.x = new_x;
		map->p.y = new_y;
		ft_init_game(game);
		ft_printf("WIIIIIIIIIIIIINN!! :O");
		mlx_destroy_window(game->vars.mlx, game->vars.win);
		exit (0);
	}
}

int	ft_handle_key(int keycode, t_game *game)
{
	t_map	*map;
	int		new_x;
	int		new_y;

	map = &game->map;
	if (keycode == 53)
		ft_close(keycode, game);
	ft_update_player_position(keycode, map, &new_x, &new_y);
	if (map->map[new_y][new_x] == SPACE || map->map[new_y][new_x] \
		== COLLECTABLE)
	{
		ft_printf("Steps: %d\n", ++game->steps);
		if (map->map[new_y][new_x] == COLLECTABLE)
			map->collectable--;
		map->map[map->p.y][map->p.x] = SPACE;
		map->map[new_y][new_x] = PLAYER;
		map->p.x = new_x;
		map->p.y = new_y;
		ft_init_game(game);
	}
	ft_handle_player_exit(game, new_x, new_y);
	return (0);
}
