/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:34:50 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/09/29 17:47:40 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_visited(t_game *game)
{
	int	i;
	int	j;
	t_map	*map = &game->map;

	i = 0;
	game->map.visited = malloc(sizeof(bool *) * map->size[0]);
	if (!game->map.visited)
		return (-1);
	while (i < map->size[0])
	{
		game->map.visited[i] = malloc(sizeof(bool) * map->size[1]);
		if (!game->map.visited[i])
			return (-1);
		j = 0;
		while (j < map->size[1])
		{
			game->map.visited[i][j] = false;
			if (ft_isplayer(game->map.map[i][j]))
			{
				map->p.x = j;
				map->p.y = i;
				map->player++;
				game->map.visited[i][j] = true;
			}
			if (ft_iscollectable(game->map.map[i][j]))
				map->collectable++;
			if (ft_isexit(game->map.map[i][j]))
				map->exit++;
			j++;
		}
		i++;
	}
	return (0);
}

t_position	ft_check_north(t_game *game, t_position current)
{
	t_position	new_element;

	new_element.x = -1;
	new_element.y = -1;
	if (current.y - 1 >= 0 && game->map.map[current.y - 1][current.x] != WALL)
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

t_position ft_check_south(t_game *game, t_position current)
{
	t_position new_element;

	new_element.x = -1;
	new_element.y = -1;
	if (current.y + 1 < game->map.size[0] && game->map.map[current.y + 1]\
		[current.x] != WALL)
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
	if (current.x + 1 < game->map.size[1] && \
		game->map.map[current.y][current.x + 1] != WALL)
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
	if (current.x - 1 >= 0 && game->map.map[current.y][current.x - 1] != WALL)
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
	ft_dequeue(&game->queue);
	if (north.x != -1)
		ft_enqueue(&game->queue, north);
	if (east.x != -1)
		ft_enqueue(&game->queue, east);
	if (south.x != -1)
		ft_enqueue(&game->queue, south);
	if (west.x != -1)
		ft_enqueue(&game->queue, west);
}

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

int	ft_init_game(t_game *game)
{
	int		i;
	int		j;
	void	*space_ptr;
	int		sp_width;
	int		sp_height;

	i = 0;
	space_ptr = mlx_xpm_file_to_image(game->vars.mlx, "./images/SPACE.xpm", \
	&sp_width, &sp_height);
	while (i < game->map.size[0])
	{
		j = 0;
		while (j < game->map.size[1])
		{
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, space_ptr, \
			j * sp_width, i * sp_height);
			game->image = ft_get_image(game->map.map[i][j], game->vars.mlx, game);
			{

				mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
				game->image.xpm_ptr, j * game->image.img_width, \
				i * game->image.img_height);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int ft_close_game(int keycode, t_vars *vars)
{
	if (keycode == KEY_Q || keycode == KEY_ESC)
	{
		printf("Movements: %d\n", 3);
		printf("CLOSED\n");
		mlx_clear_window(vars->mlx, vars->win);
		exit(2);
	}
	return (0);
}

/* void	ft_game_win(t_game *game, t_map *map, int new_x, int new_y)
{
	if (game->map.collectable == 0 && map->map[new_y][new_x] == EXIT)
	{
		map->map[map->p.y][map->p.x] = SPACE;
		map->map[new_y][new_x] = PLAYER;
		map->p.x = new_x;
		map->p.y = new_y;
		ft_init_game(game);
		mlx_destroy_window(game->vars.mlx, game->vars.win);
		exit (0);
	}
} */

void	ft_close(int keycode, t_vars *vars)
{

	if (keycode == KEY_Q || keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
}

int	ft_handle_key(int keycode, t_game *game)
{
	t_map	*map;
	int		new_x;
	int		new_y;

	map = &game->map;
	new_x = map->p.x;
	new_y = map->p.y;
	ft_close(keycode, &game->vars);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		new_x = map->p.x - 1;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		new_x = map->p.x + 1;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		new_y = map->p.y + 1;
	else if (keycode == KEY_UP || keycode == KEY_W)
		new_y = map->p.y - 1;
	else
		ft_printf("Mouvement non valide !");
	if (map->map[new_y][new_x] == SPACE || map->map[new_y][new_x] == COLLECTABLE)
	{
		game->steps++;
		if (map->map[new_y][new_x] == COLLECTABLE)
			map->collectable--;
		map->map[map->p.y][map->p.x] = SPACE;
		map->map[new_y][new_x] = PLAYER;
		map->p.x = new_x;
		map->p.y = new_y;
		ft_init_game(game);
	}
	if (game->map.collectable == 0 && map->map[new_y][new_x] == EXIT)
	{
		map->map[map->p.y][map->p.x] = SPACE;
		map->map[new_y][new_x] = PLAYER;
		map->p.x = new_x;
		map->p.y = new_y;
		ft_init_game(game);
		ft_free_elements(1, "WIN!", game);
		mlx_destroy_window(game->vars.mlx, game->vars.win);
		exit (0);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_game	game;

	game.map = (t_map){0};
	game.queue = (t_queue){0};
	/* 	game.steps = 0; */
	ft_check_args(argc, argv, &game);
	ft_get_map(&game);
	ft_check_map(&game);
	game.vars.mlx = mlx_init();
	if (!game.vars.mlx)
		exit(1);
	game.vars.win = mlx_new_window(game.vars.mlx, game.map.size[1] * 50,\
	game.map.size[0] * 50, "so_long");
	if (!game.vars.win)
		exit(1);
	ft_init_game(&game);
	mlx_hook(game.vars.win, 2, 0, ft_handle_key, &game);
	mlx_loop(game.vars.mlx); 
	return (0);
}
