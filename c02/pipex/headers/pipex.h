/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:01:42 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/01 14:22:51 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft.h"
# include "p.h"
# include "ft_printf.h"
# include <errno.h>
# include <profile.h>

# define FEW_ARGS "Error: Not enough arguments. Please provide input file, \
command 1, command 2, and output file.\n"
# define TOOMANY_ARGS "Error: too many arguments provided. Please provide \
input file, command 1, command 2, and output file.\n"
# define PIPE "pipe"
/* Structures */
/* Structures */
typedef struct s_args
{
	char	*cmd1[3];
	char	*cmd2[3];
}	t_args;

typedef struct s_fd
{
	int		infile;
	int		outfile;
	int		pipe[2];
	int		pipe_out[2];
	pid_t	process_id;
	pid_t	process_id2;
}	t_fd;

void	test_print(void);
int		ft_check_args(int argc, char **argv, t_fd *fd);
int		ft_set_pipe(int *pipefd);
int		ft_set_pipes(int *pipefd, int *pipedfd_out);
void	ft_setargs(t_args *args, char **argv, char **envp);
void	ft_stdout_to_pipe(t_args args, t_fd fd);
void	ft_pipeoutput_to_file(t_args args, t_fd fd);

#endif