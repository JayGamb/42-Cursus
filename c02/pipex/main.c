/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:19:00 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/03/16 17:03:00 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char **argv)
{

	char	*command_path;
	char	*arguments[3];
	char	**commands1;
	char	*file1;

	file1 = argv + 1;

	commands1 = ft_split(argv + 2, ' ');
	command_path = ft_strcat("/bin/";
	arguments[0] = command_path;
	arguments[1] = "-la";
	arguments[2] = NULL;
	if (argc  == 5)
	if (argc > 2)
	{

		p(1 SS (argv[1]) NL);
		execve(command_path, arguments, NULL);
		printf("OK!");
	}
	return (0);
}