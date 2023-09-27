/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:34:50 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/09/25 15:27:11 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ft_init_visited(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	game->map.visited = malloc(sizeof(bool *) * map->size[0]);
// 	if (!game->map.visited)
// 		return (-1);

// 	while (i < map->size[0])
// 	{
// 		game->map.visited[i] = malloc(sizeof(bool) * map->size[1]);
// 		if (!game->map.visited[i])
// 			return (-1);
// 		j = 0;
// 		while (j < map->size[1])
// 		{
// 			game->map.visited[i][j] = false;
// 			if (ft_isplayer(game->map.map[i][j]))
// 			{
// 				map->p.x = j;
// 				map->p.y = i;
// 				map->player++;
// 				game->map.visited[i][j] = true;
// 			}
// 			if (ft_iscollectable(game->map.map[i][j]))
// 				map->collectable++;
// 			if (ft_isexit(game->map.map[i][j]))
// 				map->exit++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }
// 		/* 	printf("number of exits :%d\t number of collectables :%d\n", map->exit, map->collectable); */

// t_position	ft_check_north(t_map *map, t_position current)
// {
// 	t_position	new_element;

// 	new_element.x = -1;
// 	new_element.y = -1;
// 	if (current.y - 1 >= 0 && game->map.map[current.y - 1][current.x] != WALL)
// 	{
// 		if (game->map.visited[current.y - 1][current.x] == false)
// 		{
// 			game->map.visited[current.y - 1][current.x] = true;
// 			new_element.x = current.x;
// 			new_element.y = current.y - 1;
// 		}
// 	}
// 	return (new_element);
// }

// t_position ft_check_south(t_map *map, t_position current)
// {
// 	t_position new_element;

// 	new_element.x = -1;
// 	new_element.y = -1;
// 	if (current.y + 1 < map->size[0] && game->map.map[current.y + 1][current.x] != WALL)
// 	{
// 		if (game->map.visited[current.y + 1][current.x] == false)
// 		{
// 			game->map.visited[current.y + 1][current.x] = true;
// 			new_element.x = current.x;
// 			new_element.y = current.y + 1;
// 		}
// 	}
// 	return (new_element);
// }

// t_position	ft_check_east(t_map *map, t_position current)
// {
// 	t_position	new_element;

// 	new_element.x = -1;
// 	new_element.y = -1;
// 	if (current.x + 1 < map->size[1] && game->map.map[current.y][current.x + 1] != WALL)
// 	{
// 		if (game->map.visited[current.y][current.x + 1] == false)
// 		{
// 			game->map.visited[current.y][current.x + 1] = true;
// 			new_element.x = current.x + 1;
// 			new_element.y = current.y;
// 		}
// 	}
// 	return (new_element);
// }

// t_position	ft_check_west(t_map *map, t_position current)
// {
// 	t_position	new_element;

// 	new_element.x = -1;
// 	new_element.y = -1;
// 	if (current.x - 1 >= 0 && game->map.map[current.y][current.x - 1] != WALL)
// 	{
// 		if (game->map.visited[current.y][current.x - 1] == false)
// 		{
// 			game->map.visited[current.y][current.x - 1] = true;
// 			new_element.x = current.x - 1;
// 			new_element.y = current.y;
// 		}
// 	}
// 	return (new_element);
// }

// void	ft_explore_neighbors(t_map *map, t_position current, t_queue *queue)
// {
// 	t_position	north;
// 	t_position	south;
// 	t_position	west;
// 	t_position	east;

// 	north = ft_check_north(map, current);
// 	south = ft_check_south(map, current);
// 	west = ft_check_west(map, current);
// 	east = ft_check_east(map, current);
// 	ft_dequeue(queue);
// 	if (north.x != -1)
// 		ft_enqueue(queue, north);
// 	if (east.x != -1)
// 		ft_enqueue(queue, east);
// 	if (south.x != -1)
// 		ft_enqueue(queue, south);
// 	if (west.x != -1)
// 		ft_enqueue(queue, west);
// }

// void	ft_navigate(t_map *map, t_queue *queue)
// {
// 	t_element	*current;

// 	if (ft_enqueue(queue, map->p) < 0)
// 		ft_free_elements(5, MALLOC_ERR, map, queue);
// 	current = queue->first;
// 	while (current)
// 	{
// 		ft_explore_neighbors(map, current->position, queue);
// 		if (ft_iscollectable(
// 				game->map.map[current->position.y][current->position.x]))
// 			map->collectable--;
// 		printf("number of exits :%d\t number of collectables :%d\n", map->exit, map->collectable);
// 		current = current->next;
// 	}
// }

// t_image	ft_get_image(char element, void *mlx)
// {
// 	t_image	image;

// 	if (element == WALL)
// 		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/Block_A_02.xpm", &image.img_width, &image.img_height);
// /* 	if (element == SPACE)
// 		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/SPACE.xpm", &image.img_width, &image.img_height); */
// 	if (element == COLLECTABLE)
// 		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/ball.xpm", &image.img_width, &image.img_height);
// 	if (element == EXIT)
// 		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/Flag_B.xpm", &image.img_width, &image.img_height);
// 	if (element == PLAYER)
// 		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/1walk.xpm", &image.img_width, &image.img_height);
// 	return (image);
// }

// int	ft_init_game(void *mlx, void *mlx_win, t_map	*map)
// {

// 	int		i;
// 	int		j;
// 	void	*space_ptr;
// 	int		sp_width, sp_height;
// 	t_image	image;
	
// 	i = 0;
// 	space_ptr = mlx_xpm_file_to_image(mlx, "./images/SPACE.xpm", &sp_width, &sp_height);
// 	while (i < map->size[0])
// 	{
// 		j = 0;
// 		while (j < map->size[1])
// 		{
// 		 	mlx_put_image_to_window(mlx, mlx_win, space_ptr, j * sp_width, i * sp_height);
// 			image = ft_get_image(game->map.map[i][j], mlx);
// 			{
// 				mlx_put_image_to_window(mlx, mlx_win, image.xpm_ptr, j * image.img_width, i * image.img_height);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int ft_close_game(int keysym, void *param)
// {
// 	if (keysym == KEY_Q || keysym == KEY_ESC)
// 	{
// 		printf("Movements: %d\n", 3);
// 		printf("CLOSED\n");
		
// 		exit(2);
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_vars	vars;
// 	t_map	*map;
// 	t_queue	*queue;

// 	map = malloc(sizeof(t_map));
// 	queue = malloc(sizeof(t_queue));
// 	ft_check_initalloc(map, queue);
// 	ft_check_args(argc, argv, map, queue);
// 	ft_get_map(map, queue);
// 	ft_check_map(map, queue);
// 	printf("OK, CEST DONNNEEEEEEEE!");
// 	vars.mlx = mlx_init();
// 	if (vars.mlx == 0)
// 		ft_free_elements(5, "An error with 'mlx_init' pointer accured", map, queue);
// 	vars.win = mlx_new_window(vars.mlx, map->size[1] * 50, map->size[0] * 50, "so_long");
// 	if (vars.win == 0)
// 		ft_free_elements(5, "An error with 'mlx_win' pointer accured", map, queue);
// 	mlx_key_hook(vars.win, ft_close_game, &vars);

// 	ft_init_game(vars.mlx, vars.win, map);
// 	mlx_loop(vars.mlx);
// 	return (0);
// }

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
		/* 	printf("number of exits :%d\t number of collectables :%d\n", map->exit, map->collectable); */

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
	if (current.y + 1 < game->map.size[0] && game->map.map[current.y + 1][current.x] != WALL)
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
	if (current.x + 1 < game->map.size[1] && game->map.map[current.y][current.x + 1] != WALL)
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

void	ft_navigate(t_game *game)
{
	t_element	*current;

	if (ft_enqueue(&game->queue, game->map.p) < 0)
		ft_printerr("enqueue ft_enqueue error", 2);
		/* ft_free_elements(5, MALLOC_ERR, &game->map, &game->queue); */
	current = game->queue.first;
	while (current)
	{
		ft_explore_neighbors(game, current->position);
		if (ft_iscollectable(
				game->map.map[current->position.y][current->position.x]))
			game->map.collectable--;
		printf("number of exits :%d\t number of collectables :%d\n", game->map.exit, game->map.collectable);
		current = current->next;
	}
}

t_image	ft_get_image(char element, void *mlx)
{
	t_image	image;

	if (element == WALL)
		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/Block_A_02.xpm", &image.img_width, &image.img_height);
/* 	if (element == SPACE)
		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/SPACE.xpm", &image.img_width, &image.img_height); */
	if (element == COLLECTABLE)
		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/ball.xpm", &image.img_width, &image.img_height);
	if (element == EXIT)
		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/Flag_B.xpm", &image.img_width, &image.img_height);
	if (element == PLAYER)
		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/1walk.xpm", &image.img_width, &image.img_height);
	return (image);
}

int	ft_init_game(t_game *game)
{

	int		i;
	int		j;
	void	*space_ptr;
	int		sp_width, sp_height;
	
	i = 0;
	space_ptr = mlx_xpm_file_to_image(game->vars.mlx, "./images/SPACE.xpm", &sp_width, &sp_height);
	while (i < game->map.size[0])
	{
		j = 0;
		while (j < game->map.size[1])
		{
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, space_ptr, j * sp_width, i * sp_height);
			game->image = ft_get_image(game->map.map[i][j], game->vars.mlx);
			{
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->image.xpm_ptr, j * game->image.img_width, i * game->image.img_height);
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

int	ft_close(int keycode, t_vars *vars)
{

	if (keycode == KEY_Q || keycode == KEY_ESC)
		mlx_destroy_window(vars->mlx, vars->win);
	else
		printf("KEY : %d \n", keycode);
	return (0);
}

/* int	main(int argc, char **argv)
{
	t_vars	game;
	game.map = malloc(sizeof(t_map));
	game.queue = malloc(sizeof(t_queue));
	ft_check_initalloc(&game.map, &game.queue);
	ft_check_args(argc, argv, &game.map, &game.queue);
	ft_get_map(&game.map, &game.queue);
	ft_check_map(&game.map, &game.queue);
	printf("OK, CEST DONNNEEEEEEEE!");
	game.vars.mlx = mlx_init();
	if (game.vars.mlx == 0)
		ft_free_elements(5, "An error with 'mlx_init' pointer accured", &game->map, &game->queue);
	game.vars.win = mlx_new_window(vars.mlx, map->size[1] * 50, map->size[0] * 50, "so_long");
	if (game.vars.win == 0)
		ft_free_elements(5, "An error with 'mlx_win' pointer accured", &game->map, &game->queue);
	ft_init_game(game);
	mlx_key_hook(game.vars.win, ft_close_game, &vars);
	mlx_loop(vars.mlx);
	return (0);
} */

int main(int argc, char **argv)
{
	t_game game;

	game.map = (t_map){0};
	game.queue = (t_queue){0};
	// ft_check_initalloc(&game);
	ft_check_args(argc, argv, &game);
	ft_get_map(&game);
	ft_check_map(&game);

	printf("OK, C'EST FAIT!");

	game.vars.mlx = mlx_init();
	if (!game.vars.mlx)
		exit(1);
//		ft_free_elements(5, "An error with 'mlx_init' occurred", &game);
	game.vars.win = mlx_new_window(game.vars.mlx, game.map.size[1] * 50,\
	game.map.size[0] * 50, "so_long");
	if (!game.vars.win)
		exit(1);
//	ft_free_elements(5, "An error with 'mlx_win' occurred", &game);
	ft_init_game(&game);
	mlx_hook(game.vars.win, 2, 1L<<0, ft_close, &game.vars);
	mlx_loop(game.vars.mlx);

	return (0);
}
