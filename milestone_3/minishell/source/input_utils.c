/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:49:24 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/15 14:33:46 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	do_ignore(char *input)
{
	if (input[0] == '#')
		return (1);
	if (unclose_quotes(input) == 1)
	{
		ft_putendl_fd("unclosed quotes detected", STDERR_FILENO);
		return (1);
	}
	return (0);
}

void	update_input(char **input, char *var_value, char *second_part)
{
	char	*first_part;
	char	*updated_input;

	if (!*input[0] && !var_value)
		first_part = ft_strdup("");
	else if (!*input[0] && var_value)
		first_part = ft_strdup(var_value);
	else if (!var_value)
		first_part = ft_strdup(*input);
	else
		first_part = ft_strjoin(*input, var_value);
	updated_input = ft_strjoin(first_part, second_part);
	free(first_part);
	free(*input);
	*input = updated_input;
}

void	null_input(char **input, t_env **env)
{
	if (*input == NULL)
	{
		ctrl_exit(input, env);
		return ;
	}
}

int	input_error(char *input, t_env *env, int *status)
{
	int	res;

	res = 0;
	if (empty_input(input))
		res = 1;
	else if (unclose_quotes(input))
		res = 1;
	else if (is_invalid_input(input))
	{
		*status = 2;
		res = 1;
	}
	else if (handle_hd(input, status, env) == 0)
		res = 1;
	if (res == 1)
		free(input);
	return (res);
}
