/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:32:51 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/12 15:17:39 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_fork_error(char *input, t_env *env)
{
	ft_print_perror("fork", input);
	env->statu = EXIT_FAILURE;
}

int	exec_builtins_fork(char **args, t_env **env)
{
	int	status;

	status = exec_builtins(args, *env);
	ft_free_array(args);
	free_ft_env(env);
	rl_clear_history();
	exit(status);
}

void	exec_forked_multi(char *cmd, char **cmds, t_env **env)
{
	char	**args;

	close_unused_fds();
	args = split_input(cmd);
	ft_free_array(cmds);
	if (is_builtins(args[0]))
		exec_builtins_fork(args, env);
	else
		execute_extern(args, *env);
}

int	exec_forked(char **args, t_env *env)
{
	int		c_pid;
	char	*cmd;

	cmd = args[0];
	c_pid = fork();
	execute_signals(c_pid);
	if (c_pid == -1)
		ft_print_perror("fork", cmd);
	else if (c_pid == 0)
		execute_extern(args, env);
	else
		return (wait_child(c_pid, 1));
	exit(EXIT_FAILURE);
}
