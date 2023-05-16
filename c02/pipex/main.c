/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:19:00 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/16 15:33:35 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void print_args(int argc, char **argv) 
{
	printf("Number of arguments: %d\n", argc);
	for (int i = 0; i < argc; i++) {
			printf("Argument %d: %s\n", i, argv[i]);
	}
}

char	*get_commandline(char **argv)
{
	char	*cmd_line;
	int		i;

	i = 0;
	if (!argv)
		return (NULL);
	cmd_line = argv[i];
	i++;
	while (argv[i])
	{
		cmd_line = ft_strjoin(cmd_line, " ");
		cmd_line = ft_strjoin(cmd_line, argv[i++]);
	}
	return (cmd_line);
}

void	ft_secondchild(t_args args, t_fd fd)
{
	ft_pipeoutput_to_file(args, fd);
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;
	t_fd	fd;
	int		id2;

	id2 = 0;
	id2++;
	if (ft_set_pipe(fd.pipe))
		return (1);
	args.cmd1[2] = NULL;
	if (ft_check_args(argc, argv, &fd) == 0)
		ft_setargs(&args, argv, envp);
	fd.process_id = fork();
	if (fd.process_id == -1)
	{
		
		perror("Error: Fork failed");
		exit(1);
	}
	if (fd.process_id == 0)
		ft_stdout_to_pipe(args, fd, envp);
	fd.process_id2 =  fork();
	if (fd.process_id2 == 0)
		ft_secondchild(args, fd);
	close(fd.pipe[1]);
	waitpid(fd.process_id, NULL, 0);
	waitpid(id2, NULL, 0);
	return (0);
}
