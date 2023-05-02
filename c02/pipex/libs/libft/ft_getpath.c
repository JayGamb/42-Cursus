/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:20:14 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/02 14:45:57 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getpath(char **envp, char *prog)
{
	char	**env;
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break ;
		i++;
	}
	env = ft_split(envp[i] + 5, ':');
	i = 0;
	while (env[i])
	{
		path = ft_strjoin(env[i], "/");
		path = ft_strjoin(path, prog);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}
