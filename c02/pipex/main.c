/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:19:00 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/03 15:50:46 by jgamboa-         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
/* 	t_args	args;
	t_fd	fd; */

/* 	if (ft_set_pipe(fd.pipe))
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
		ft_stdout_to_pipe(args, fd);
	else
	{
		ft_pipeoutput_to_file(args, fd);
		waitpid(fd.process_id, NULL, 0);
	} */
	(void)envp;

	
	if (argc < 1)
		return (1);
	char *string = get_commandline(argv);
	printf("%s\n", string);
	return (0);
}
