/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:44:32 by candriam          #+#    #+#             */
/*   Updated: 2024/12/17 08:57:04 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "structure.h"
# include <stdbool.h>

// void	execve_error(char *path, char **args, t_env *envs);
void	execve_error(char *path, char **args, char **envs);
void	terminate_exec(char **args, int status, t_env *envs);
int		execute_extern(char **args, t_env *envs);

#endif
