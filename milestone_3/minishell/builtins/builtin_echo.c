/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:07:43 by candriam          #+#    #+#             */
/*   Updated: 2024/12/03 16:41:12 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static bool	is_n_option(char *args)
{
	int	pos;

	pos = 1;
	if (args[0] != '-')
		return (false);
	while (args[pos])
	{
		if (args[pos] != 'n')
			return (false);
		pos++;
	}
	return (true);
}

int	builtin_echo(char **argv, t_env *env)
{
	int		pos;
	bool	flag;

	pos = 1;
	flag = true;
	while (argv[pos] && is_n_option(argv[pos]))
	{
		flag = false;
		pos++;
	}
	while (argv[pos])
	{
		ft_putstr_fd(argv[pos], STDOUT_FILENO);
		if (argv[pos + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		pos++;
	}
	if (flag)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	env->statu = 0;
	return (0);
}
