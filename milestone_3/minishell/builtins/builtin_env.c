/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:56:51 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 11:03:07 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_print_error_env(char *command, char *str, t_env *envp)
{
	ft_putstr_fd("env: ", STDERR_FILENO);
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	envp->statu = 1;
}

int	builtin_env(t_env *envp, char **args)
{
	t_env	*curr;

	curr = envp;
	if (args[1])
	{
		ft_print_error_env("use without argument or option", args[1], envp);
		return (EXIT_FAILURE);
	}
	while (curr)
	{
		if (ft_strchr(curr->data, '='))
			ft_putendl_fd(curr->data, STDOUT_FILENO);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
