/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:00:44 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 11:04:17 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main_loop(t_env *env)
{
	char	*input;
	int		exit;
	int		status;

	exit = 0;
	status = EXIT_SUCCESS;
	while (!exit)
	{
		init_signals();
		input = readline("_> ");
		add_history(input);
		null_input(&input, &env);
		if (input_error(input, env, &status))
			continue ;
		if (input && *input)
			status = process_input(input, env, status);
		else
			free(input);
	}
	return (status);
}

int	main(int argc, char **argv, char **environ)
{
	int	status;

	status = EXIT_SUCCESS;
	if (argv != NULL && argc > 1)
	{
		ft_putendl_fd("minishell can not take arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	status = main_loop(ft_copy_environs(environ));
	return (status);
}
