/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:05:27 by candriam          #+#    #+#             */
/*   Updated: 2024/09/14 15:09:08 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_ctrl_c(int status)
{
	return (WTERMSIG(status) == SIGINT);
}

int	is_ctrl_slash(int status)
{
	return (WTERMSIG(status) == SIGQUIT);
}

int	handle_sig_int(int status, int is_last)
{
	if (is_ctrl_c(status))
		ft_putstr_fd("\n", STDOUT_FILENO);
	if (is_ctrl_slash(status) && is_last)
		ft_putstr_fd("Quit\n", STDOUT_FILENO);
	return (INTERRUPT + WTERMSIG(status));
}

int	wait_child(int c_pid, int is_last)
{
	int		status;
	char	*str;

	status = 0;
	if (c_pid == FORK_ERROR)
		return (EXIT_FAILURE);
	if (waitpid(c_pid, &status, 0) == -1)
	{
		str = ft_itoa(c_pid);
		ft_print_perror("waitpid", str);
		free(str);
	}
	if (WIFSIGNALED(status))
		return (handle_sig_int(status, is_last));
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}

int	wait_child_status(int c_pid[1024])
{
	int	pos;
	int	status;
	int	is_last;

	pos = 0;
	status = 0;
	while (c_pid[pos] != 0)
	{
		is_last = c_pid[pos + 1] == 0;
		status = wait_child(c_pid[pos], is_last);
		pos++;
	}
	close_unused_fds();
	free(c_pid);
	return (status);
}
