/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:03:19 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 16:45:33 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	open_file(char *filename, int is_writable)
{
	int	fd;

	if (is_writable == 0)
		fd = open(filename, O_RDONLY, 0777);
	else if (is_writable == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		return (-1);
	if (fd == -1)
		ft_print_perror("open", filename);
	return (fd);
}

int	create_here_doc(const char *delim)
{
	int		pipe_fds[2];
	char	*line;

	if (pipe(pipe_fds) == -1)
		return (-1);
	while (1)
	{
		line = readline("~> ");
		if (!line || ft_strcmp(line, delim) == 0)
		{
			free(line);
			break ;
		}
		write(pipe_fds[1], line, ft_strlen(line));
		write(pipe_fds[1], "\n", 1);
		free(line);
	}
	close(pipe_fds[1]);
	return (pipe_fds[0]);
}

t_heredoc	**get_heredoc(void)
{
	static t_heredoc	*resources = NULL;

	return (&resources);
}

void	set_heredoc(t_heredoc *new_resources)
{
	t_heredoc	**resources_ptr;

	resources_ptr = get_heredoc();
	*resources_ptr = new_resources;
}

void	free_hd(t_heredoc *resources)
{
	if (resources)
	{
		if (resources->tmp_fd != -1)
			close(resources->tmp_fd);
		if (resources->delim)
			free(resources->delim);
		if (resources->env)
			free_ft_env(&resources->env);
		rl_clear_history();
		free(resources);
	}
}
