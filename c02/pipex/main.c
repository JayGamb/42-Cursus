/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:19:00 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/10 17:30:38 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (void)
{
	int id = fork();
	int n;

	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
		wait(&id);
	for (int i = n; i < n + 5; i++)
	{
		ft_printf("Current ID: %d, parent %d", getpid);
		fflush(stdout);
	}
	p(1 NL);
	return (0);
}