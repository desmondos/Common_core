/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:39:04 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 11:03:35 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	remove_from_new_env(char *var_name, t_env **env)
{
	t_env	*curr;
	t_env	*prev;

	curr = *env;
	prev = NULL;
	while (curr)
	{
		if (ft_strncmp(curr->data, var_name, ft_strlen(var_name)) == 0
			&& (curr->data[ft_strlen(var_name)] == '='
				|| curr->data[ft_strlen(var_name)] == '\0'))
		{
			if (prev)
				prev->next = curr->next;
			else
				*env = curr->next;
			free(curr->data);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

int	builtin_unset(char **args, t_env **env)
{
	char	*var_name;
	int		status;

	args++;
	status = EXIT_SUCCESS;
	if (!*args)
		return (status);
	while (*args)
	{
		var_name = *args;
		if (!is_valid_varname(var_name))
		{
			ft_putendl_fd("unset: error", STDERR_FILENO);
			status = EXIT_FAILURE;
		}
		else
			remove_from_new_env(var_name, env);
		args++;
	}
	return (status);
}
