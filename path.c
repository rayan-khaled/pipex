/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:58:28 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/06 14:26:19 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*iterate_path(char **paths, char *part_path, char *full_path, char *cmd)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(full_path, X_OK) == 0)
		{
			free_arr(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_arr(paths);
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*part_path;
	char	*full_path;

	part_path = NULL;
	full_path = NULL;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (iterate_path(paths, part_path, full_path, cmd));
}
