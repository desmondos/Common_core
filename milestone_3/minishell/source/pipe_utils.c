/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:49:43 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/12 14:48:22 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	has_pipe(char *str)
{
	while (*str)
	{
		if (*str == '\'')
		{
			str++;
			while (*str != '\'')
				str++;
		}
		if (*str == '"')
		{
			str++;
			while (*str != '"')
				str++;
		}
		if (*str == '|')
			return (1);
		str++;
	}
	return (0);
}

char	*get_pipes(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] == '\'' || str[pos] == '"')
		{
			pos++;
			while (str[pos] != '\'' && str[pos] != '"')
				pos++;
		}
		if (str[pos] == '|')
			return (str);
		pos++;
	}
	return (NULL);
}

void	handle_pipe(int fd_out, char *curr, char **cmds)
{
	int			is_first_cmd;
	int			has_next_cmd;
	char		*last_cmd;
	static int	pipe_fd[2];

	last_cmd = cmds[ft_len(cmds) - 1];
	is_first_cmd = (curr == cmds[0]);
	has_next_cmd = (curr != last_cmd);
	if (!is_first_cmd)
		redir_fd(pipe_fd[0], STDIN_FILENO);
	if (has_next_cmd)
	{
		if (pipe(pipe_fd) == -1)
			ft_print_perror("pipe", curr);
		else
			redir_fd(pipe_fd[1], STDOUT_FILENO);
	}
	else
		redir_fd(fd_out, STDOUT_FILENO);
}
