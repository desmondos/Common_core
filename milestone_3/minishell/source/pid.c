/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:32:51 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/19 11:18:57 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_child(char **cmds, t_env **env)
{
	rl_clear_history();
	free_ft_env(env);
	ft_free_array(cmds);
	close_all_fds();
	exit(EXIT_FAILURE);
}

int	*init_c_pid(char **cmds)
{
	int		*c_pid;
	size_t	len;

	len = sizeof(int) * (ft_len(cmds) + 1);
	c_pid = malloc(len);
	if (!c_pid)
		return (NULL);
	ft_bzero(c_pid, len);
	return (c_pid);
}

static void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	process_heredoc(int *status, t_env *env, char *delim, int hd_nbr)
{
	t_heredoc	*resources;
	char		*file_name;
	int			tmp_fd;

	resources = safe_malloc(sizeof(t_heredoc));
	file_name = tmp_name(hd_nbr);
	tmp_fd = open_tmp_file(file_name);
	if (tmp_fd == -1)
	{
		free(resources);
		exit(EXIT_FAILURE);
	}
	free(file_name);
	init_resources(resources, env, delim, tmp_fd);
	set_heredoc(resources);
	configure_signal_handler();
	heredoc_loop(status, env, resources);
	if (!resources->read_line)
		ft_print_error("warning: heredoc delimited by EOF. Wanted", delim);
	free(resources->read_line);
	free_hd(resources);
	close_all_fds();
	exit(EXIT_SUCCESS);
}
