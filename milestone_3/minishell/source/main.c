/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:00:44 by candriam          #+#    #+#             */
/*   Updated: 2024/12/20 14:00:38 by frajaona         ###   ########.fr       */
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
	int		status;
	t_env	*env_vars;

	status = EXIT_SUCCESS;
	if (argv != NULL && argc > 1)
	{
		ft_putendl_fd("minishell can not take arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	env_vars = ft_copy_environs(environ);
	status = main_loop(env_vars);
	ft_free_array(environ);
	free_ft_env(&env_vars);
	return (status);
}
