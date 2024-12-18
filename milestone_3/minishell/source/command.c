/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:02:02 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 11:03:45 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execve_error(char *path, char **args, char **envs)
{
	int	status;

	status = EXIT_FAILURE;
	if (path == NULL)
	{
		ft_print_perror("execve", args[0]);
		status = CMD_NOT_FOUND;
		ft_free_array(envs);
		ft_free_array(args);
		exit(status);
	}
	ft_print_perror("execve", args[0]);
	status = EXIT_FAILURE;
	if (access(path, F_OK) != 0)
		status = CMD_NOT_FOUND;
	else if (access(path, X_OK) != 0)
		status = NOT_EXECUTABLE;
	free(path);
	ft_free_array(envs);
	ft_free_array(args);
	exit(status);
}

void	terminate_exec(char **args, int status, t_env *envs)
{
	if (status == NOT_EXECUTABLE)
		ft_print_error(args[0], NOT_EXECUTABLE_MSG);
	else if (status == CMD_NOT_FOUND)
		ft_print_error(args[0], CMD_NOT_FOUND_MSG);
	rl_clear_history();
	free_ft_env(&envs);
	if (args != NULL)
		ft_free_array(args);
	close_all_fds();
	exit(status);
}

static int	ft_env_has_path(t_env *env)
{
	return (ft_env_val("PATH", env) != NULL);
}

int	execute_extern(char **args, t_env *envs)
{
	char	*path;
	char	**env;

	if (is_blank(args[0]))
		terminate_exec(args, EXIT_SUCCESS, envs);
	if (is_dir(args[0]))
		terminate_exec(args, NOT_EXECUTABLE, envs);
	path = get_executable_path(args[0], envs);
	if (path == NULL && ft_env_has_path(envs))
	{
		if (is_path(args[0]))
			path = ft_strdup(args[0]);
		else
			terminate_exec(args, CMD_NOT_FOUND, envs);
	}
	rl_clear_history();
	close_unused_fds();
	env = create_ft_environ(envs);
	free_ft_env(&envs);
	if (execve(path, args, env) == -1)
		execve_error(path, args, env);
	ft_free_array(env);
	exit(EXIT_SUCCESS);
}
