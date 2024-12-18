/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:56:05 by candriam          #+#    #+#             */
/*   Updated: 2024/08/01 00:38:15 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	show_usage_exit(int should_exit, char *av)
{
	if (should_exit == 1)
		ft_putstr_fd("./pipex infile cmd1 cmd2 outfile\n", 2);
	if (should_exit == 2)
		ft_printf("zsh: no such file or directory: %s\n", av);
	exit(0);
}

void	free_str_array(char **array)
{
	int	pos;

	pos = 0;
	while (array[pos])
	{
		free(array[pos]);
		pos++;
	}
	free(array);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}

char	*gent_env_value(char *key, char **env)
{
	int		i;
	int		key_len;
	char	*sub_key;

	i = 0;
	while (env[i])
	{
		key_len = 0;
		while (env[i][key_len] && env[i][key_len] != '=')
			key_len++;
		sub_key = ft_substr(env[i], 0, key_len);
		if (ft_strcmp(sub_key, key) == 0)
		{
			free(sub_key);
			return (env[i] + key_len +1);
		}
		free(sub_key);
		i++;
	}
	return (NULL);
}

char	*get_executable_path(char *command, char **env)
{
	int		path_index;
	char	*full_path;
	char	*part_path;
	char	**path_dir;
	char	**command_part;

	path_index = -1;
	path_dir = ft_split(gent_env_value("PATH", env), ':');
	command_part = ft_split(command, 32);
	while (path_dir[++path_index])
	{
		part_path = ft_strjoin(path_dir[path_index], "/");
		full_path = ft_strjoin(part_path, command_part[0]);
		free(part_path);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_str_array(command_part);
			return (full_path);
		}
		free(full_path);
	}
	free_str_array(path_dir);
	free_str_array(command_part);
	return (command);
}
