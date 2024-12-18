/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 01:51:34 by candriam          #+#    #+#             */
/*   Updated: 2024/07/28 10:33:19 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"
# include "libftprintf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024

# endif

void	show_usage_exit(int should_exit, char *av);
void	free_str_array(char **array);
void	execute_command(char *command, char **env);
void	parent_process(char **argv, int *pipe_fd, char **env);
void	child_process(char **argv, int *pipe_fd, char **env);

char	*gent_env_value(char *key, char **env);
char	*get_executable_path(char *command, char **env);

int		main(int argc, char **argv, char **env);
int		open_file(char *filename, int is_writable);
int		ft_strcmp(const char *str1, const char *str2);

#endif
