/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:21:53 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 11:02:46 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_print_error_cd(char *command, char *str)
{
	(void)str;
	ft_putstr_fd("cd: ", STDERR_FILENO);
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	builtin_cd(char **argv, t_env *envp)
{
	if (argv[1] && argv[2])
		return (ft_print_error_cd("too many arguments", argv[1]));
	if (argv[1] && ft_str_equal(argv[1], "-"))
	{
		envp->old = ft_env_val("OLDPWD", envp);
		if (!envp->old || !*envp->old)
			return (ft_print_error_cd("OLDPWD not set", NULL));
		envp->dir = envp->old;
		ft_putendl_fd(envp->dir, STDOUT_FILENO);
	}
	else if (argv[1] && !ft_str_equal(argv[1], "~"))
		envp->dir = argv[1];
	else
		envp->dir = ft_env_val("__HOME", envp);
	if (chdir(envp->dir) != 0)
		return (ft_print_error_cd("No such file or directory", argv[1]));
	envp->pwd = ft_env_val("PWD", envp);
	envp->old = ft_env_val("OLDPWD", envp);
	if (envp->pwd && *envp->pwd && envp->old)
		update_ft_env("OLDPWD", envp->pwd, envp);
	if (envp->pwd && *envp->pwd)
		update_ft_env("PWD", getcwd(envp->cwd, ENV_SIZE), envp);
	return (EXIT_SUCCESS);
}
