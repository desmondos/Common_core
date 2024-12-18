/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:25:06 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 11:03:22 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	handle_declare(t_env *env)
{
	t_env	*curr;
	char	*var_name;

	curr = env;
	while (curr)
	{
		var_name = get_var_name(curr->data);
		if (var_name)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(var_name, STDOUT_FILENO);
			if (ft_strchr(curr->data, '='))
			{
				ft_putstr_fd("=\"", STDOUT_FILENO);
				ft_putstr_fd(get_var_value(curr->data), STDOUT_FILENO);
				ft_putstr_fd("\"", STDOUT_FILENO);
			}
			ft_putstr_fd("\n", STDOUT_FILENO);
			free(var_name);
		}
		curr = curr->next;
	}
	return (0);
}

static int	handle_export_no_args(t_env *env)
{
	handle_declare(env);
	return (EXIT_SUCCESS);
}

static void	proc_add_back(char *var_name, char *data, char *sign, t_env **env)
{
	char	*temp;

	if (sign)
		add_back(data, env);
	else
	{
		temp = ft_strjoin(var_name, "");
		if (temp == NULL)
		{
			ft_putendl_fd("Erreur: allocation at export", STDERR_FILENO);
			return ;
		}
		add_back(temp, env);
		free(temp);
	}
}

static int	process_export_argument(char *data, t_env **env)
{
	int		status;
	char	*equal_sign;
	char	*var_name;

	status = EXIT_SUCCESS;
	equal_sign = ft_strchr(data, '=');
	var_name = get_var_name(data);
	if (!is_valid_varname(var_name) || ft_str_equal(data, "="))
	{
		ft_putendl_fd("export: not a valid identifier", STDERR_FILENO);
		status = EXIT_FAILURE;
	}
	else if (ft_env_var(var_name, *env))
	{
		if (equal_sign)
			update_ft_env(var_name, get_var_value(data), *env);
	}
	else
		proc_add_back(var_name, data, equal_sign, env);
	free(var_name);
	return (status);
}

int	builtin_export(char **args, t_env **env)
{
	int	status;

	status = EXIT_SUCCESS;
	args++;
	if (!*args)
		status = handle_export_no_args(*env);
	else
	{
		while (*args)
		{
			status = process_export_argument(*args, env);
			if (status == EXIT_FAILURE)
				break ;
			args++;
		}
	}
	return (status);
}
