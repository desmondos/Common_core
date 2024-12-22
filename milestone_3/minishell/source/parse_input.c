/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:04:48 by candriam          #+#    #+#             */
/*   Updated: 2024/12/20 15:30:49 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	restore_subst_space(char **input)
{
	char	*str;

	while (*input)
	{
		str = *input;
		while (*str)
		{
			if (*str == -1)
				*str = ' ';
			str++;
		}
		input++;
	}
	return ;
}

void	substitute_spaces(char *str, char delimeter)
{
	while (*str && *str != delimeter)
		str++;
	if (*str)
		str++;
	while (*str && *str != delimeter)
	{
		if (*str == ' ')
			*str = -1;
		str++;
	}
	if (*str)
		str++;
	if (*str)
		substitute_spaces(str, delimeter);
}

static char	**refact_arg(char **args)
{
	int		j;

	j = 0;
	while (j < ft_len(args))
	{
		if ((args[j][0] == '"' && args[j][1] == '"')
			|| (args[j][0] == '\'' && args[j][1] == '\''))
		{
			if (j > 0)
				rm_quotes(args[j]);
			j++;
		}
		else
		{
			rm_quotes(args[j]);
			j++;
		}
	}
	return (args);
}

char	**split_input(char *input)
{
	char	**args;

	if (!has_quote_sign(input))
		return (ft_split(input, ' '));
	substitute_spaces(input, '"');
	substitute_spaces(input, '\'');
	args = ft_split(input, ' ');
	restore_subst_space(args);
	refact_arg(args);
	return (args);
}
