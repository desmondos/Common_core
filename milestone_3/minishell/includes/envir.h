/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:44:32 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 16:51:39 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIR_H
# define ENVIR_H

# include "structure.h"
# include <aio.h>
# include <stdbool.h>

char	*create_ft_env_data(char *var_name, char *var_value);
void	handle_ft_env_var(char *var_name, char *var_value, t_env *env);
void	update_ft_env(char *var_name, char *var_value, t_env *env);
void	free_ft_env(t_env **env);
void	ft_create_env_node(char *data, t_env **head);
char	*get_var_value(char *data);
char	*get_var_name(char *data);
size_t	ft_env_len(t_env *env);
t_env	*ft_copy_environs(char **environ);
t_env	*ft_env_var(char *var_name, t_env *env);
void	add_back(char *data, t_env **node);
char	*ft_env_val(char *var_name, t_env *env);
char	**create_ft_environ(t_env *env);

void	expand_var(char **input, t_env *env);
char	*get_exit_status(char *input);
void	update_input_exit(char **input, char *exit_code, char *second_part);
void	expand_exit_status(char **input, int status);
void	handle_expansions(char **input, t_env *env, int status);

#endif
