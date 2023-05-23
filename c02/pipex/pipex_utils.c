/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:22:47 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/23 12:55:58 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* check_args.c */

#include "pipex.h"

void	ft_command_error(char *prog)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(prog, 2);
	ft_putendl_fd(": command not found", 2);
	exit(127);
}

int	ft_findindx_envp(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break ;
	}
	return (i);
}

char	*ft_getpath(char **envp, char *prog)
{
	char	**env;
	char	*path;
	char	*new_path;
	char	*temp;
	int		i;

	path = NULL;
	i = ft_findindx_envp(envp);
	env = ft_split(envp[i] + 5, ':');
	i = -1;
	while (env[++i])
	{
		temp = ft_strjoin(env[i], "/");
		new_path = ft_strjoin(temp, prog);
		free(temp);
		if (access(new_path, X_OK) == 0)
		{
			free(path);
			path = new_path;
			break ;
		}
		else
			free(new_path);
	}
	return (path);
}

void	ft_stdout_to_pipe(t_args *args, t_fd fd, char **argv, char **envp)
{
	if (close(fd.pipe[0]) < 0)
		ft_printerror("PIPE", 1);
	if (dup2(fd.infile, STDIN_FILENO) < 0)
		ft_printerror("DUP2", 1);
	if (dup2(fd.pipe[1], STDOUT_FILENO) < 0)
		ft_printerror("DUP2", 1);
	if (close(fd.pipe[1]) < 0)
		ft_printerror("PIPE", 1);
	args->cmd1_tokens = ft_split((const char *)argv[2], ' ');
	args->cmd1[0] = ft_getpath(envp, args->cmd1_tokens[0]);
	if (args->cmd1[0] == NULL)
		ft_command_error(args->cmd1_tokens[0]);
	args->cmd1[1] = args->cmd1_tokens[1];
	args->cmd1[2] = args->cmd1_tokens[2];
	args->cmd1[3] = NULL;
	execve(args->cmd1[0], args->cmd1, envp);
}

void	ft_pipeoutput_to_file(t_args *args, t_fd fd, char **argv, char **envp)
{
	if (close(fd.pipe[1]) == -1)
		ft_printerror("Pipe", 1);
	if (dup2(fd.pipe[0], STDIN_FILENO) == -1)
		ft_printerror("DUP2_ERR", 1);
	if (dup2(fd.outfile, STDOUT_FILENO) == -1)
		ft_printerror("DUP2_ERR", 1);
	if (close(fd.pipe[0]) == -1)
		ft_printerror("Pipe", 1);
	args->cmd2_tokens = ft_split((const char *)argv[3], ' ');
	args->cmd2[0] = ft_getpath(envp, args->cmd2_tokens[0]);
	if (args->cmd2[0] == NULL)
	{
		close(fd.pipe[1]);
		ft_command_error(args->cmd2_tokens[0]);
	}
	args->cmd2[1] = args->cmd2_tokens[1];
	args->cmd2[2] = args->cmd2_tokens[2];
	args->cmd2[3] = NULL;
	waitpid(fd.process_id, NULL, 0);
	execve(args->cmd2[0], args->cmd2, envp);
}
