/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:03:05 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 07:54:22 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <fcntl.h>

typedef struct s_heredoc
{
    char	*read_line;
    char	*file_name;
    int		tmp_fd;
    t_env	*env;
    char	*delim;
}				t_heredoc;

t_heredoc *g_heredoc = NULL;

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

int	check_hd_syntax(char *input)
{
	if (input[0] == '<' && input[1] == '<')
		return (syn_error("<<"));
	else if (input[0] == '>' && input[1] == '>')
		return (syn_error(">>"));
	input[1] = '\0';
	return (syn_error(input));
}

void	sigint_handler(int sig)
{
	(void)sig;
	if (g_heredoc)
	{
		if (g_heredoc->file_name) free(g_heredoc->file_name);
		if (g_heredoc->delim) free(g_heredoc->delim);
		free_ft_env(&g_heredoc->env);
		rl_clear_history();
		free(g_heredoc);
		exit(130);
	}
}

void	process_heredoc(int *status, t_env *env, char *delim, int hd_nbr)
{
	g_heredoc = malloc(sizeof(t_heredoc));
	if (!g_heredoc)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	g_heredoc->env = env;
	g_heredoc->delim = delim;
	g_heredoc->file_name = tmp_name(hd_nbr);
	g_heredoc->tmp_fd = open(g_heredoc->file_name, O_CREAT
			| O_RDWR | O_TRUNC, 0644);
	signal(SIGINT, sigint_handler);
	g_heredoc->read_line = readline("~> ");
	while (g_heredoc->read_line && !ft_str_equal(g_heredoc->read_line,
			g_heredoc->delim))
	{
		expand_exit_status(&g_heredoc->read_line, *status);
		expand_var(&g_heredoc->read_line, g_heredoc->env);
		ft_putendl_fd(g_heredoc->read_line, g_heredoc->tmp_fd);
		free(g_heredoc->read_line);
		g_heredoc->read_line = readline("~> ");
	}
	if (!g_heredoc->read_line)
		ft_print_error("warning: heredoc delimited wanted", g_heredoc->delim);
	free(g_heredoc->read_line);
	close(g_heredoc->tmp_fd);
	free(g_heredoc->file_name);
	free(g_heredoc->delim);
	free_ft_env(&g_heredoc->env);
	rl_clear_history();
	free(g_heredoc);
	g_heredoc = NULL;
	exit(EXIT_SUCCESS);
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
		process_heredoc(status, env, delim, hd_nbr);
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
	return (1);
}
