/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:04:48 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 15:11:27 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	in_redir(char *cmd)
{
	int		fd;
	char	*redir;
	char	*file;

	redir = redir_pos(cmd, '<');
	if (!redir)
		return (1);
	file = extract_filename(redir);
	fd = open(file, O_RDONLY, FD_CLOEXEC);
	if (fd == -1)
	{
		ft_print_perror("open", file);
		free(file);
		return (0);
	}
	else
		redir_fd(fd, STDIN_FILENO);
	free(file);
	return (1);
}

int	out_redir(char *cmd)
{
	int		fd;
	int		flags;
	char	*file;
	char	*out;

	out = redir_pos(cmd, '>');
	if (!out)
		return (1);
	if (out[1] == '>')
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	file = extract_filename(out);
	fd = open(file, flags, 0644);
	if (fd == -1)
	{
		ft_print_perror("open", file);
		free(file);
		return (0);
	}
	else
		redir_fd(fd, STDOUT_FILENO);
	free(file);
	return (1);
}

void	redir_heredoc(char *cmd, int hd_nbr)
{
	char	*filename;
	int		tmp_fd;
	char	*hd_pos;

	filename = tmp_name(hd_nbr);
	tmp_fd = open(filename, O_RDONLY);
	if (tmp_fd == -1)
	{
		ft_print_perror("open", filename);
		free(filename);
		return ;
	}
	free(filename);
	redir_fd(tmp_fd, STDIN_FILENO);
	hd_pos = redir_pos(cmd, hd_nbr);
	use_memmove(hd_pos);
}

void	handle_redirects(char *cmd, char **cmds, t_env **env)
{
	char	redir;

	redir = has_multi_redir(cmd);
	while (redir)
	{
		if (redir == '<')
		{
			if (in_redir(cmd) == 0)
				exit_child(cmds, env);
		}
		if (redir == '>')
		{
			if (out_redir(cmd) == 0)
				exit_child(cmds, env);
		}
		if (redir < 0)
			redir_heredoc(cmd, redir);
		redir = has_multi_redir(cmd);
	}
}
