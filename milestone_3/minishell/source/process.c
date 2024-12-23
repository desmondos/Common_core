/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:04:07 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 11:04:39 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**get_path_directories(t_env *env)
{
	char	*path;
	char	**res;

	path = ft_env_val("PATH", env);
	if (path)
	{
		res = ft_split(path, ':');
		return (res);
	}
	else
		return (NULL);
}

char	*build_full_path(char *dir, char *command)
{
	char	*part_path;
	char	*full_path;

	part_path = ft_strjoin(dir, "/");
	if (part_path)
		full_path = ft_strjoin(part_path, command);
	else
		full_path = NULL;
	free(part_path);
	return (full_path);
}

char	*find_executable_in_path(char **path_dirs, char *command)
{
	int		path_index;
	char	*full_path;

	path_index = 0;
	while (path_dirs[path_index])
	{
		full_path = build_full_path(path_dirs[path_index], command);
		if (full_path && access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		path_index++;
	}
	return (NULL);
}

char	*get_executable_path(char *command, t_env *env)
{
	char	**path_dirs;
	char	*executable_path;
	char	curr[PATH_MAX];

	executable_path = NULL;
	if (!command || !env)
		return (NULL);
	if (command[0] == '.' && command[1] == '/')
	{
		executable_path = ft_strjoin(getcwd(curr, PATH_MAX), command);
		if (executable_path && access(executable_path, F_OK | X_OK) != 0)
		{
			free(executable_path);
			return (NULL);
		}
	}
	else
	{
		path_dirs = get_path_directories(env);
		if (path_dirs)
			executable_path = find_executable_in_path(path_dirs, command);
		ft_free_array(path_dirs);
	}
	return (executable_path);
}
