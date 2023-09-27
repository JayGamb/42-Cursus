/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:45:48 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/08/29 15:06:18 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_enqueue(t_queue *queue, t_position positon)
{
	t_element *new_element;

	new_element = malloc(sizeof(t_element));
	if (!new_element)
		return (-1);
	new_element->position = positon;
	new_element->next = NULL;
	if (queue->first != NULL)
	{
		queue->last->next = new_element;
		queue->last = new_element;
	}
	else
	{
		queue->first = new_element;
		queue->last = new_element;
	}
	return (0);
}

t_position ft_dequeue(t_queue *queue)
{
	t_element *temp;
	t_position temp_position;

	temp_position.x = -1;
	temp_position.y = -1;
	if (queue->first == NULL)
		return (temp_position);
	temp = queue->first;
	temp_position = temp->position;
	queue->first = queue->first->next;
	if (queue->first == NULL)
		queue->last = NULL;
	free (temp);
	return (temp_position);
}