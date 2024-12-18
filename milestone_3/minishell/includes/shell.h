/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:46:38 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 16:49:53 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "structure.h"

void	execute_child_process(char **args, t_env *env);
int		exec_single_command(char *cmd, t_env **env);
int		handle_pipe_execution(char **cmd, t_env **env);

int		is_invalid_start_redirect(char *input, int i);
int		redirect_check(char *input);
int		invalid_input(char *input);
bool	has_quotes_and_operator(const char *cmd, const char *oper);

void	restore_subst_space(char **input);
void	substitute_spaces(char *str, char delimeter);
char	**split_input(char *input);

void	exit_child(char **cmds, t_env **env);
int		*init_c_pid(char **cmds);

int		in_redir(char *cmd);
int		out_redir(char *cmd);
void	redir_heredoc(char *cmd, int hd_nbr);
void	handle_redirects(char *cmd, char **cmds, t_env **env);

char	*redir_pos(char *input, char redir);
char	has_multi_redir(char *input);
int		manage_redirects(char *cmd, int fd[2]);
int		handle_in_redir(char *cmd, int fd[2]);
int		handle_out_redir(char *cmd, int fd[2]);

int		is_quote(char c);
int		has_quote(char *input);
int		has_quote_sign(char *str);
void	rm_quotes(char *str);

#endif
