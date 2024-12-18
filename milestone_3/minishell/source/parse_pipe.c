/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:49:43 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/12 15:35:24 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	temp_subst_pipe(char *input, char delim)
{
	while (*input && *input != delim)
		input++;
	if (*input)
		input++;
	while (*input && *input != delim)
	{
		if (*input == '|')
			*input = -1;
		input++;
	}
	if (*input)
		input++;
	if (*input)
		temp_subst_pipe(input, delim);
}

void	restore_subst_pipe(char **input)
{
	char	*str;

	while (*input)
	{
		str = *input;
		while (*str)
		{
			if (*str == -1)
				*str = '|';
			str++;
		}
		input++;
	}
	return ;
}

char	**split_commands(char *input)
{
	char	**commands;

	temp_subst_pipe(input, '"');
	temp_subst_pipe(input, '\'');
	commands = ft_split(input, '|');
	restore_subst_pipe(commands);
	return (commands);
}
