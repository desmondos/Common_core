/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:45:23 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 16:26:30 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_OUT_H
# define IN_OUT_H

# include "structure.h"
# include <stdbool.h>

void	close_unused_fds(void);
void	close_all_fds(void);
void	handle_in_fd(int fd[2]);
void	handle_out_fd(int fd[2]);
void	save_fds(int fds[2]);

void	redir_fd(int fd_to, int fd_at);
void	restore_fd(int fd[2]);

void	handle_fork_error(char *input, t_env *env);
int		exec_builtins_fork(char **args, t_env **env);
void	exec_forked_multi(char *cmd, char **cmds, t_env **env);
int		exec_forked(char **args, t_env *env);

int		is_special_char(char c);
int		is_dir(char *input);
int		is_path(char *input);

char	*get_hd_pos(char *str);
int		check_hd_syntax(char *input);
void	process_heredoc(int *status, t_env *env, char *delim, int hd_nbr);
int		exec_heredoc(char *delim, int hd_nbr, int *status, t_env *env);
int		handle_hd(char *input, int *status, t_env *env);

int		open_file(char *filename, int is_writable);
int		create_here_doc(const char *delim);

#endif
