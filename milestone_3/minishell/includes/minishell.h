/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:52:40 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 16:47:06 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_ENV 1024
# define CMD_NOT_FOUND 127
# define NOT_EXECUTABLE 126
# define INTERRUPT 128
# define CMD_NOT_FOUND_MSG "command not found"
# define NOT_EXECUTABLE_MSG "Is a directory"
# define IN 0
# define OUT 1
# define FORK_ERROR -1
# define MISUSE_CMD 2

# include <sys/stat.h>
# include <curses.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/wait.h>
# include <term.h>
# include <unistd.h>

# include "builtins.h"
# include "command.h"
# include "in_out.h"
# include "libft.h"
# include "pipe.h"
# include "process.h"
# include "shell.h"
# include "signals.h"
# include "structure.h"
# include "utils.h"
# include "check.h"
# include "envir.h"

int	main(int argc, char **argv, char **environ);
int	main_loop(t_env *env);

#endif
