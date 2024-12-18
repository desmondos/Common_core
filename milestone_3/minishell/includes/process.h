/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:46:00 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 16:37:42 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "structure.h"

char	**get_path_directories(t_env *env);
char	*build_full_path(char *dir, char *command);
char	*find_executable_in_path(char **path_dirs, char *command);
char	*get_executable_path(char *command, t_env *env);

int		is_delimit(char c);
int		get_filename_end(char *name);
void	use_memmove(char *str);
char	*extract_filename(char *str);
char	*tmp_name(int hd_nbr);

int		process_in_input(char *input, t_env *env);
int		process_input(char *input, t_env *env, int status);
#endif
