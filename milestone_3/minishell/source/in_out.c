/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:03:05 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 18:23:15 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_hd_pos(char *str)
{
	while (*str && str[1])
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
		if (*str == '<' && str[1] == '<')
			return (str);
		str++;
	}
	return (NULL);
}

void	heredoc_loop(int *status, t_env *env, t_heredoc *resources)
{
	char	*read_line;

	read_line = readline("~> ");
	while (read_line && !ft_str_equal(read_line, resources->delim))
	{
		expand_exit_status(&read_line, *status);
		expand_var(&read_line, env);
		ft_putendl_fd(read_line, resources->tmp_fd);
		free(read_line);
		read_line = readline("~> ");
	}
	resources->read_line = read_line;
}

void	sigint_handler(int sig)
{
	t_heredoc	**resources;

	(void)sig;
	resources = get_heredoc();
	free_hd(*resources);
	close_all_fds();
	exit(130);
}

int	exec_heredoc(char *delim, int hd_nbr, int *status, t_env *env)
{
	int	c_pid;

	c_pid = fork();
	heredoc_signals(c_pid);
	if (c_pid == -1)
	{
		ft_print_perror("fork - heredoc_prompt", delim);
		return (0);
	}
	else if (c_pid == 0)
	{
		process_heredoc(status, env, delim, hd_nbr);
		free(delim);
		free_ft_env(&env);
	}
	else
	{
		*status = wait_child(c_pid, TRUE);
		init_signals();
		if (*status != EXIT_SUCCESS)
			return (0);
	}
	return (1);
}

int	handle_hd(char *input, int *status, t_env *env)
{
	static int	hd_nbr;
	char		*hd_pos;
	char		*delim;

	hd_nbr = -1;
	hd_pos = get_hd_pos(input);
	if (!hd_pos)
		return (1);
	hd_nbr--;
	*hd_pos = hd_nbr;
	hd_pos++;
	delim = extract_filename(hd_pos);
	if (!exec_heredoc(delim, hd_nbr, status, env))
	{
		free(delim);
		return (0);
	}
	free(delim);
	return (handle_hd(input, status, env));
}
