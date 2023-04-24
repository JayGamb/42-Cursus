/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:11:01 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/04/20 18:16:18 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* set_pipes.c */

#include "pipex.h"

int ft_set_pipe(int *pipefd)
{
	if (pipe(pipefd) == -1)
	{
		perror("Error creating pipe");
		return 1;
	}
	return (0);
}

int ft_set_pipes(int *pipefd, int *pipefd_out)
{
	if (ft_set_pipe(pipefd) != 0|| ft_set_pipe(pipefd_out) != 0)
		return (1);
	return (0);
}

void	ft_stdout_to_pipe(t_args args, t_fd fd)
{
	close(fd.pipe[0]);
	dup2(fd.infile, STDIN_FILENO);
	close(fd.infile);
	dup2(fd.pipe[1], STDOUT_FILENO);
	close(fd.pipe[1]);
	if (execve(args.cmd1[0], args.cmd1, NULL) < 0)
		perror("execve1");
}

void	ft_pipeoutput_to_file(t_args args, t_fd fd)
{
	close(fd.pipe[1]);
	dup2(fd.pipe[0], STDIN_FILENO);
	close(fd.infile);
	dup2(fd.outfile, STDOUT_FILENO);
	close(fd.outfile);
	if(execve(args.cmd2[0], args.cmd2, NULL) < 0)
		perror("execve2");
}