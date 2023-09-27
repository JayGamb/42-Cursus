/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:34:50 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/09/27 16:27:08 by jgamboa-         ###   ########.fr       */
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
		/* printf("number of exits :%d\t number of collectables :%d\n", game->map.exit, game->map.collectable); */
		current = current->next;
	}
}

t_image	ft_get_image(char element, void *mlx)
{
	t_image	image;

	if (element == WALL)
		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/Block_A_02.xpm", &image.img_width, &image.img_height);
 	if (element == SPACE)
		image.xpm_ptr = mlx_xpm_file_to_image(mlx, "./images/SPACE.xpm", &image.img_width, &image.img_height);
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
	printf("size0: %d\tsize1: %d\n", game->map.size[0], game->map.size[1]);
	while (i < game->map.size[0])
	{
		j = 0;
		printf("Je suis là %d\n", i);
		while (j < game->map.size[1])
		{printf("Je suis làjjj %d\n", j);
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, space_ptr, j * sp_width, i * sp_height);
			game->image = ft_get_image(game->map.map[i][j], game->vars.mlx);
			{
				printf("%p\n", game->image.xpm_ptr);
				mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->image.xpm_ptr, j * game->image.img_width, i * game->image.img_height);
				printf("oups %d\n", j);
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


int ft_move_player(int keycode, t_game *game)
{
	t_map	*map = &game->map;

	if (keycode == KEY_LEFT)
	{
		
/* 		map->map[map->p.y][map->p.x] = '0'; */
		map->map[map->p.y][map->p.x-1] = 'P';
		ft_init_game(game);
	}
	else if (keycode == KEY_RIGHT)
	{
		
		map->map[map->p.y][map->p.x+1] = 'P';
		ft_init_game(game);
	}
	else if (keycode == KEY_DOWN)
	{
		map->map[map->p.y-1][map->p.x] = 'P';
		ft_init_game(game);
	}
	if (keycode == KEY_UP)
	{
		
		map->map[map->p.y][map->p.x] = '0';
		map->map[map->p.y+1][map->p.x] = 'P';
		ft_init_game(game);
	}

	else
		printf("Ca marche pas!");
	return 0;
}

int main(int argc, char **argv)
{
	t_game game;

	printf("Je suis là -1\n");
	game.map = (t_map){0};
	game.queue = (t_queue){0};
	// ft_check_initalloc(&game);
	printf("Je suis là 0\n");
	ft_check_args(argc, argv, &game);
	printf("Je suis là 1\n");
	ft_get_map(&game);
	printf("Je suis là 2\n");
	ft_check_map(&game);
	printf("Je suis là 3\n");
	printf("OK, C'EST FAIT!\n");

 	game.vars.mlx = mlx_init();
	if (!game.vars.mlx)
		exit(1);
//		ft_free_elements(5, "An error with 'mlx_init' occurred", &game);
	game.vars.win = mlx_new_window(game.vars.mlx, game.map.size[1] * 50,\
	game.map.size[0] * 50, "so_long");
	printf("Je suis là 4\n");
	if (!game.vars.win)
		exit(1);
//	ft_free_elements(5, "An error with 'mlx_win' occurred", &game);
	ft_init_game(&game);
	printf("Je suis là 5\n");
	mlx_hook(game.vars.win, 2, 0, ft_close, &game.vars);
	mlx_hook(game.vars.win, 2, 0, ft_move_player, &game.vars);
	mlx_loop(game.vars.mlx); 

	return (0);
}