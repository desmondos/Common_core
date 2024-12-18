/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:32:51 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/18 16:59:42 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redir_fd(int from, int to)
{
	dup2(from, to);
	close(from);
}

void	restore_fd(int fd[2])
{
	if (fd[0] != -1)
		redir_fd(fd[0], STDIN_FILENO);
	if (fd[1] != -1)
		redir_fd(fd[1], STDOUT_FILENO);
}

int	open_tmp_file(char *file_name)
{
	int	tmp_fd;

	tmp_fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (tmp_fd == -1)
		perror("open");
	return (tmp_fd);
}

void	init_resources(t_heredoc *res, t_env *env, char *delim, int tmp_fd)
{
	res->env = env;
	res->delim = delim;
	res->read_line = NULL;
	res->tmp_fd = tmp_fd;
}

void	configure_signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
}
