/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:03:48 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 16:12:58 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	empty_input(char *input)
{
	int	pos;

	pos = 0;
	if (input == NULL)
		return (1);
	while (input[pos])
	{
		if (ft_isspace(input[pos]) == 0)
			return (0);
		pos++;
	}
	return (1);
}

int	unclose_quotes(char *str)
{
	char	last_opened;

	last_opened = 0;
	while (*str && !last_opened)
	{
		if (*str == '\'' || *str == '"')
			last_opened = *str;
		str++;
	}
	while (*str && last_opened)
	{
		if (*str && *str == last_opened)
			last_opened = 0;
		str++;
	}
	if (*str)
		return (unclose_quotes(str));
	else if (!last_opened)
		return (0);
	else
	{
		ft_putendl_fd("unclose_quotes detected", STDERR_FILENO);
		return (1);
	}
}

int	is_invalid_input(char *input)
{
	if (pipe_start_input(input))
		return (1);
	if (empty_pipe(input))
		return (1);
	if (invalid_redirect(input))
		return (1);
	return (0);
}

int	pipe_start_input(char *input)
{
	if (input[0] == '|')
	{
		syn_error("|");
		return (1);
	}
	return (0);
}

char	*get_pipes(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] == '\'' || str[pos] == '"')
		{
			pos++;
			while (str[pos] != '\'' && str[pos] != '"')
				pos++;
		}
		if (str[pos] == '|')
			return (str);
		pos++;
	}
	return (NULL);
}
