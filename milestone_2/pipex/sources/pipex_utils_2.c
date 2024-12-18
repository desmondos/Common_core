/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:55:04 by candriam          #+#    #+#             */
/*   Updated: 2024/08/01 00:44:33 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file(char *filename, int is_writable)
{
	int	file_descriptor;

	if (is_writable == 0)
		file_descriptor = open(filename, O_RDONLY, 0777);
	if (is_writable == 1)
		file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (is_writable == -1)
		exit(0);
	return (file_descriptor);
}

void	execute_command(char *command, char **env)
{
	char	*executable_path;
	char	**command_part;

	command_part = ft_split(command, ' ');
	if (!command_part)
		exit(1);
	executable_path = get_executable_path(command_part[0], env);
	if (!executable_path)
	{
		ft_putstr_fd("pipex: commamd not found ", 2);
		ft_putendl_fd(command_part[0], 2);
		free_str_array(command_part);
		exit(0);
	}
	if (execve(executable_path, command_part, env) == -1)
	{
		free_str_array(command_part);
		exit(1);
	}
}

void	child_process(char **argv, int *pipe_fd, char **env)
{
	int	input_fd;

	input_fd = open_file(argv[1], 0);
	dup2(input_fd, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	execute_command(argv[2], env);
}

void	parent_process(char **argv, int *pipe_fd, char **env)
{
	int	input_fd;
	int	status;

	input_fd = open_file(argv[4], 1);
	dup2(input_fd, 1);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	execute_command(argv[3], env);
	wait(&status);
}
