/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:19:00 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/06 16:10:54 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (void)
{
	int id = fork();
	p(1 SS "Hello World from " II (id) NL);
	if (id == 0)
		p(1 SS "Hello from the new process" NL);
	else
	{
		p(1 SS "Hello from the main process" NL);
	}
	
	return (0);
}