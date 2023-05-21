/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:19:00 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/21 15:36:35 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* main.c */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_args	args;
	t_fd	fd;

	ft_check_args(argc, argv, &fd);
	if (pipe(fd.pipe) == -1)
		ft_printerror("PIPE", 1);
	fd.process_id = fork();
	if (fd.process_id < 0)
		ft_printerror("FORK", 1);
	if (fd.process_id == 0)
		ft_stdout_to_pipe(&args, fd, argv, envp);
	fd.process_id2 = fork();
	if (fd.process_id2 < 0)
		ft_printerror("FORK", 1);
	if (fd.process_id2 == 0)
		ft_pipeoutput_to_file(&args, fd, argv, envp);
	close(fd.pipe[1]);
	waitpid(fd.process_id, NULL, 0);
	waitpid(fd.process_id2, NULL, 0);
}
