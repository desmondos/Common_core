/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:25:06 by candriam          #+#    #+#             */
/*   Updated: 2024/12/21 08:37:52 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	expand_var(char **input, t_env *env)
{
	char	*var_position;
	char	*var_name;
	char	*var_value;
	int		name_size;

	if (is_dollar_quote(*input) == true)
		remove_dollar(*input);
	else
	{
		var_position = var_pos(*input);
		if (var_position)
		{
			name_size = 0;
			while (is_var_name(var_position[name_size + 1]))
				name_size++;
			var_name = ft_substr(var_position, 1, name_size);
			*var_position = '\0';
			var_value = ft_env_val(var_name, env);
			update_input(input, var_value, (var_position + 1 + name_size));
			free(var_name);
			expand_var(input, env);
		}
	}
}

char	*get_exit_status(char *input)
{
	while (input && *input)
	{
		if (*input == '\'')
			input = skip_single_quotes(input);
		else if (*input == '$' && input[1] == '?')
			return (input);
		else
			input++;
	}
	return (NULL);
}

void	update_input_exit(char **input, char *exit_code, char *second)
{
	char	*first;
	char	*updated_input;

	first = ft_strjoin(*input, exit_code);
	updated_input = ft_strjoin(first, second);
	free(*input);
	free(first);
	*input = updated_input;
}

void	expand_exit_status(char **input, int status)
{
	char	*exit_status_position;
	char	*exit_status_str;

	exit_status_position = get_exit_status(*input);
	if (exit_status_position)
	{
		*exit_status_position = '\0';
		exit_status_str = ft_itoa(status);
		update_input_exit(input, exit_status_str, (exit_status_position + 2));
		free(exit_status_str);
		expand_exit_status(input, status);
	}
}

void	handle_expansions(char **input, t_env *env, int status)
{
	if (input[0] && ft_strstr(input[0], "<<") && ft_strstr(input[0], "$")
		&& ft_strstr(input[0], "<<") < ft_strstr(input[0], "$"))
	{
		free(input);
		return ;
	}
	else
	{
		expand_exit_status(input, status);
		expand_var(input, env);
	}
}
