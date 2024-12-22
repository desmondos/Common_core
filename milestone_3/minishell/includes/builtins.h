/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:28:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/13 17:47:57 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define ENV_SIZE 4096

# include "structure.h"

int		builtin_cd(char **argv, t_env *envp);
int		builtin_exit(char **argv, t_env **env);
int		builtin_pwd(char **argv);
int		builtin_echo(char **argv, t_env *env);
int		builtin_env(t_env *envp, char **args);
int		builtin_export(char **args, t_env **env);
int		env_exist(char *var_name, t_env *env);
int		builtin_unset(char **args, t_env **envp);
int		is_builtins(char *input);
int		exec_builtins(char **args, t_env *envp);
int		exec_fork_builtins(char **args, t_env *env);
int		ctrl_exit(char **argv, t_env **env);

#endif
