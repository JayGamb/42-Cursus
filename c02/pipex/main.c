/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:19:00 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/22 14:50:14 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* main.c */

#include "pipex.h"

int	ft_check_args(int argc, char **argv, t_fd *fd)
{
	if (argc < 5)
		ft_printerror(FEW_ARGS, 2);
	else if (argc > 5)
		ft_printerror(TOOMANY_ARGS, 2);
	fd->infile = open(argv[1], O_RDONLY, 0777);
	fd->outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (fd->infile < 0)
		ft_printerror(argv[1], 2);
	else if (fd->outfile < 0)
		ft_printerror(OUTFILERR, 2);
	return (0);
}

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
