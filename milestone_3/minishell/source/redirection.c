/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:03:05 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 14:43:27 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*redir_pos(char *input, char redir)
{
	while (*input)
	{
		if (*input == '\'')
		{
			input++;
			while (*input != '\'')
				input++;
		}
		if (*input == '"')
		{
			input++;
			while (*input != '"')
				input++;
		}
		if (*input == redir)
			return (input);
		input++;
	}
	return (NULL);
}

char	has_multi_redir(char *input)
{
	while (*input)
	{
		if (*input == '\'')
		{
			input++;
			while (*input != '\'')
				input++;
		}
		if (*input == '"')
		{
			input++;
			while (*input != '"')
				input++;
		}
		if (*input == '<' || *input == '>' || *input < 0)
			return (*input);
		input++;
	}
	return (0);
}

int	manage_redirects(char *cmd, int fd[2])
{
	char	redir;

	fd[0] = -1;
	fd[1] = -1;
	redir = has_multi_redir(cmd);
	while (redir)
	{
		if (redir == '<')
		{
			if (!handle_in_redir(cmd, fd))
				return (0);
		}
		if (redir == '>')
		{
			if (!handle_out_redir(cmd, fd))
				return (0);
		}
		if (redir < 0)
		{
			handle_in_fd(fd);
			redir_heredoc(cmd, redir);
		}
		redir = has_multi_redir(cmd);
	}
	return (1);
}

int	handle_in_redir(char *cmd, int fd[2])
{
	handle_in_fd(fd);
	if (in_redir(cmd) == 0)
	{
		redir_fd(fd[0], STDIN_FILENO);
		return (0);
	}
	return (1);
}

int	handle_out_redir(char *cmd, int fd[2])
{
	handle_out_fd(fd);
	if (out_redir(cmd) == 0)
	{
		redir_fd(fd[1], STDOUT_FILENO);
		return (0);
	}
	return (1);
}
