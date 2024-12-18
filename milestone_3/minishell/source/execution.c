/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:49:43 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/18 11:04:05 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_child_process(char **args, t_env *env)
{
	execute_extern(args, env);
	ft_free_array(args);
	exit(env->statu);
}

int	exec_single_command(char *cmd, t_env **env)
{
	int		status;
	int		fd[2];
	char	**args;

	if (!manage_redirects(cmd, &fd[0]))
	{
		restore_fd(fd);
		free(cmd);
		return (EXIT_FAILURE);
	}
	args = split_input(cmd);
	free(cmd);
	if (is_builtins(args[0]))
		status = exec_builtins(args, *env);
	else
		status = exec_forked(args, *env);
	ft_free_array(args);
	restore_fd(fd);
	return (status);
}

int	handle_pipe_execution(char **cmd, t_env **env)
{
	int	fd[2];
	int	*c_pid;
	int	pos;

	save_fds(fd);
	c_pid = init_c_pid(cmd);
	pos = 0;
	while (cmd[pos])
	{
		handle_pipe(fd[1], cmd[pos], cmd);
		c_pid[pos] = fork();
		execute_signals(c_pid[pos]);
		if (c_pid[pos] == -1)
			ft_print_perror("fork", cmd[pos]);
		else if (c_pid[pos] == 0)
		{
			free(c_pid);
			handle_redirects(cmd[pos], cmd, env);
			exec_forked_multi(cmd[pos], cmd, env);
		}
		pos++;
	}
	restore_fd(fd);
	return (wait_child_status(c_pid));
}
