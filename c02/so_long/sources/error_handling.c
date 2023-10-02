/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:25:45 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/10/02 15:32:49 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_map *map)
{
	int	y;

	y = 0;
	printf("taille rows : %d\n", map->size[0]);
	while (y < map->size[0])
	{
		free(map->map[y]);
		y++;
	}
	free(map->map);
	map->map = NULL;
}

void	ft_free_visited(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size[0])
	{
		free(map->visited[i]);
		i++;
	}
	free(map->visited);
	map->visited = NULL;
}


void	ft_clean_map(t_map *map)
{
	if (!map)
		return ;
	printf("Youpi!");
	if (map->map)
		ft_free_map(map);
	if (map->visited)
		ft_free_visited(map);
}

void	ft_clean_queue(t_queue *queue)
{
	t_element	*current;
	t_element	*next;

	current = queue->first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	queue->first = NULL;
	queue->last = NULL;
	free(queue);
}


int	ft_printerr(char *message, int exit_code)
{
	if (exit_code == 1)
		ft_printf("%s", message);
	return (exit_code);
}