/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:29:54 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 11:03:16 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	fits_in_long_long(char *str)
{
	long long	out;
	int			c;

	if (ft_strlen(str) > 20)
		return (0);
	if (ft_strncmp(str, "-9223372036854775808", 21) == 0)
		return (1);
	out = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		c = *str - '0';
		if (out > (LLONG_MAX - c) / 10)
			return (0);
		out = out * 10 + c;
		str++;
	}
	return (1);
}

static void	check_args_error(char **args)
{
	char	*exit_status;

	if (!args || !args[1])
	{
		if (args)
			ft_free_array(args);
		close_all_fds();
		exit(EXIT_SUCCESS);
	}
	exit_status = args[1];
	if (!fits_in_long_long(exit_status))
	{
		ft_free_array(args);
		exit_error("exit", "numeric argument required", MISUSE_CMD);
	}
	if (args[2] != NULL)
	{
		ft_free_array(args);
		exit_error("exit", "too many arguments", EXIT_FAILURE);
	}
}

int	builtin_exit(char **argv, t_env **env)
{
	int	status;

	rl_clear_history();
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	free_ft_env(env);
	check_args_error(argv);
	close_all_fds();
	status = ft_atol(argv[1]);
	ft_free_array(argv);
	exit(status);
}

int	ctrl_exit(char **argv, t_env **env)
{
	int	status;

	(void)argv;
	status = EXIT_SUCCESS;
	ft_putendl_fd("exit", STDOUT_FILENO);
	rl_clear_history();
	free_ft_env(env);
	close_all_fds();
	exit(status);
}
