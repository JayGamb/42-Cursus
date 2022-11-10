/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:22:33 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/10 20:27:45 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*start;

	if (lst)
	{
		start = *lst;
		while (start)
		{
			tmp = start->next;
			del(start->content);
			free(start);
			start = tmp;
		}
		*lst = NULL;
	}
}
