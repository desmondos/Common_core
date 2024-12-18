/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:47:09 by candriam          #+#    #+#             */
/*   Updated: 2024/12/16 16:14:40 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

void	handle_sigint(int sig);
void	init_signals(void);
void	heredoc_signals(int c_pid);
void	execute_signals(int c_pid);

int		is_ctrl_c(int status);
int		is_ctrl_slash(int status);
int		handle_sig_int(int status, int is_last);
int		wait_child(int c_pid, int is_last);
int		wait_child_status(int c_pid[1024]);

int		exit_code(int sig, t_state state);

#endif
