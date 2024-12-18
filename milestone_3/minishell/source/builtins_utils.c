/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:02:02 by candriam          #+#    #+#             */
/*   Updated: 2024/12/15 14:32:03 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_fork_builtins(char **args, t_env *env)
{
	int	status;

	status = exec_builtins(args, env);
	ft_free_array(args);
	free_ft_env(&env);
	rl_clear_history();
	exit(status);
}

int	is_builtins(char *input)
{
	if (!input)
		return (0);
	else if (ft_strcmp(input, "echo") == 0)
		return (1);
	else if (ft_strcmp(input, "cd") == 0)
		return (1);
	else if (ft_strcmp(input, "pwd") == 0)
		return (1);
	else if (ft_strcmp(input, "export") == 0)
		return (1);
	else if (ft_strcmp(input, "unset") == 0)
		return (1);
	else if (ft_strcmp(input, "env") == 0)
		return (1);
	else if (ft_strcmp(input, "exit") == 0)
		return (1);
	else
		return (0);
}

int	exec_builtins(char **args, t_env *envp)
{
	if (ft_strcmp(args[0], "exit") == 0)
		return (builtin_exit(args, &envp));
	else if (ft_strcmp(args[0], "cd") == 0)
		return (builtin_cd(args, envp));
	else if (ft_strcmp(args[0], "pwd") == 0)
		return (builtin_pwd(args));
	else if (ft_strcmp(args[0], "echo") == 0)
		return (builtin_echo(args, envp));
	else if (ft_strcmp(args[0], "env") == 0)
		return (builtin_env(envp, args));
	else if (ft_strcmp(args[0], "export") == 0)
		return (builtin_export(args, &envp));
	else if (ft_strcmp(args[0], "unset") == 0)
		return (builtin_unset(args, &envp));
	else
		return (EXIT_FAILURE);
}
