/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:49:43 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/15 14:31:24 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	close_unused_fds(void)
{
	int	open_fd;

	open_fd = open("/tmp/last_fd", O_RDWR | O_CREAT, 0666);
	while (open_fd > STDERR_FILENO)
	{
		close(open_fd);
		open_fd--;
	}
}

void	close_all_fds(void)
{
	close_unused_fds();
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

void	handle_in_fd(int fd[2])
{
	if (fd[0] == -1)
		fd[0] = dup(STDIN_FILENO);
}

void	handle_out_fd(int fd[2])
{
	if (fd[1] == -1)
		fd[1] = dup(STDOUT_FILENO);
}

void	save_fds(int fds[2])
{
	fds[0] = dup(STDIN_FILENO);
	fds[1] = dup(STDOUT_FILENO);
}
