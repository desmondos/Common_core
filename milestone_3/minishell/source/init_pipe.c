/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:49:43 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/12 14:31:52 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_pipe_start(char *input)
{
	if (pipe_start_input(input) == 0)
		return (0);
	return (1);
}

char	*has_multi_pipe(char *str)
{
	while (*str)
	{
		if (*str == '\'')
		{
			str++;
			while (*str != '\'')
				str++;
		}
		if (*str == '"')
		{
			str++;
			while (*str != '"')
				str++;
		}
		if (*str == '|')
			return (str);
		str++;
	}
	return (NULL);
}

int	empty_pipe(char *input)
{
	char	*next_pipe;

	next_pipe = has_multi_pipe(input);
	if (!next_pipe)
		return (0);
	next_pipe++;
	while (*next_pipe == ' ' || *next_pipe == '\t')
		next_pipe++;
	if (*next_pipe == '|')
	{
		syn_error("|");
		return (0);
	}
	return (empty_pipe(next_pipe));
}
