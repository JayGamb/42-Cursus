/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:20:14 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/16 16:44:57 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetableau(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

char	*ft_getpath(char **envp, char *prog)
{
	char	**env;
	char	*path;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break ;
	}
	env = ft_split(envp[i] + 5, ':');
	i = -1;
	while (env[++i])
	{
		path = ft_strjoin(env[i], "/");
		path = ft_strjoin(path, prog);
		if (access(path, X_OK) == 0)
		{
			ft_freetableau(env);
			return (path);
		}
		else
			free(path);
	}
	exit (0);
}
