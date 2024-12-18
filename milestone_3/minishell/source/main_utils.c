/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:03:48 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 11:04:25 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_invalid_start_redirect(char *input, int i)
{
	if ((input[i] == '>' || input[i] == '<') && (!input[i + 1] || input[i
				+ 1] == '\n'))
	{
		syn_error("newline");
		return (1);
	}
	return (0);
}

int	redirect_check(char *input)
{
	int	i;

	i = skip_spaces(input, 0);
	if (is_invalid_start_redirect(input, i))
		return (1);
	while (input[i])
	{
		if (is_redirect_char(input[i]))
		{
			i = handle_redirect(input, i);
			if (i == -1)
				return (1);
		}
		else
			i++;
	}
	return (0);
}

int	invalid_input(char *input)
{
	if (empty_pipe(input))
		return (1);
	return (0);
}

bool	has_quotes_and_operator(const char *cmd, const char *operator)
{
	bool	in_double_quotes;
	bool	in_single_quotes;
	bool	has_operator;
	int		i;
	bool	to_return;

	in_double_quotes = false;
	in_single_quotes = false;
	to_return = false;
	has_operator = ft_strstr(cmd, operator) != NULL;
	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '"' && !in_single_quotes)
			in_double_quotes = !in_double_quotes;
		else if (cmd[i] == '\'' && !in_double_quotes)
			in_single_quotes = !in_single_quotes;
		i++;
	}
	if ((in_double_quotes || in_single_quotes || ft_strstr(cmd, "\"")
			|| ft_strstr(cmd, "\'")) && has_operator)
		to_return = true;
	return (to_return);
}
