/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:04:20 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 11:04:48 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	process_in_input(char *input, t_env *env)
{
	int		status;
	char	**cmd;

	status = EXIT_SUCCESS;
	if (!has_pipe(input))
		status = exec_single_command(input, &env);
	else
	{
		cmd = split_commands(input);
		free(input);
		status = handle_pipe_execution(cmd, &env);
		ft_free_array(cmd);
	}
	return (status);
}

int	process_input(char *input, t_env *env, int status)
{
	int	ctr;

	ctr = exit_code(0, READ);
	if (ctr != 0)
	{
		exit_code(0, RESET);
		status = ctr;
	}
	handle_expansions(&input, env, status);
	if (do_ignore(input))
	{
		free(input);
		signal(SIGQUIT, SIG_IGN);
		return (status);
	}
	status = process_in_input(input, env);
	return (status);
}
