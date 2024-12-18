/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:52:14 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/12 16:35:01 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "structure.h"

int		check_pipe_start(char *input);
char	*has_multi_pipe(char *str);
int		empty_pipe(char *input);

void	temp_subst_pipe(char *input, char delim);
void	restore_subst_pipe(char **input);
char	**split_commands(char *input);

int		has_pipe(char *str);
void	handle_pipe(int fd_out, char *curr, char **cmds);

#endif
