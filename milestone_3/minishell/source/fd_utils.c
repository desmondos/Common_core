/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:32:51 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/12 15:12:54 by candriam         ###   ########.fr       */
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
