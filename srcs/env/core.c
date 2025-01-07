/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <pymousss.dev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:11:42 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/07 10:56:13 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static char	*get_env_path(char **envp)
{
	int		index;
	char	*path;

	index = 0;
	path = NULL;
	while (envp[index] && !path)
	{
		if (!ft_strncmp(envp[index], "PATH=", 5))
			path = envp[index] + 5;
		index++;
	}
	return (path);
}

static char	*join_and_check(char *path, char *cmd)
{
	char	*line;
	char	*full_cmd;

	line = ft_strjoin(path, "/");
	if (!line)
		return (NULL);
	full_cmd = ft_strjoin(line, cmd);
	free(line);
	if (!full_cmd)
		return (NULL);
	if (access(full_cmd, X_OK) == 0)
		return (full_cmd);
	free(full_cmd);
	return (NULL);
}

static char	*search_in_paths(char **path_array, char *cmd)
{
	char	*result;
	int		index;

	result = NULL;
	index = 0;
	while (path_array[index] && !result)
	{
		result = join_and_check(path_array[index], cmd);
		index++;
	}
	return (result);
}

char	*pipex_find_path(char *cmd, char **envp)
{
	char	**path;
	char	*result;
	char	*env_path;

	if (cmd[0] == '/' && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	env_path = get_env_path(envp);
	if (!env_path)
		return (NULL);
	path = ft_split(env_path, ':');
	if (!path)
		return (NULL);
	result = search_in_paths(path, cmd);
	ft_free_tbl(path);
	return (result);
}
