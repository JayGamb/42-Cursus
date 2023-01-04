/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkdlist_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:52:24 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/01/03 19:48:39 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*list_init(int value)
{
	t_list *list;
	t_element   *element;

	list = malloc(sizeof(t_list));
	element = malloc(sizeof(t_element));
	if (!list || !element)
		return (0);
	element->val = value;
	element->nxt = NULL;
	list->first = element;
	return (list);
}

void stacking(t_list *list, int new_val)
{
	t_element *new_element;

	new_element = malloc(sizeof(t_element));
	if (!new_element || !list)
		exit(EXIT_FAILURE);
	new_element->val = new_val;
	new_element->nxt = list->first;
	list->first = new_element;
}

void deletion(t_list *list)
{
	t_element *eltodel;

	if (!list)
		exit(EXIT_FAILURE);
	if (list->first != 0)
	{
		eltodel = list->first;
		list->first = list->first->nxt;
		free(eltodel);
	}
}

void printlist(t_list *list)
{
	t_element *current;
	if (!list)
	{
		ft_printf("NOP!");
		exit(EXIT_FAILURE);
	}
	current = list->first;
	while (current != NULL)
	{
		ft_printf("%d\n", current->val);
		current = current->nxt;
	}
	ft_printf("----------\n");
	ft_printf("A\n\n");
}
