/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:01:42 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/21 15:34:22 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* pipex.h */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft.h"
# include "ft_printf.h"
# include <errno.h>
# include <profile.h>

# define FEW_ARGS "not enough arguments provided."
# define TOOMANY_ARGS "too many arguments provided."
# define PIPE "pipe"
# define INFILERR "Error opening file for reading"
# define OUTFILERR "Error opening file for writing"

/* Structures */
typedef struct s_args
{
	char	*cmd1[4];
	char	**cmd1_tokens;
	char	*cmd2[4];
	char	**cmd2_tokens;
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

int		ft_check_args(int argc, char **argv, t_fd *fd);
void	ft_setargs(t_args *args, char **argv, char **envp);
void	ft_stdout_to_pipe(t_args *args, t_fd fd, char **argv, char **envp);
void	ft_pipeoutput_to_file(t_args *args, t_fd fd, char **argv, char **envp);
char	*ft_getpath(char **envp, char *prog);

#endif