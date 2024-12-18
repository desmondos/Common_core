/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:04:48 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 15:36:20 by candriam         ###   ########.fr       */
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

char	**split_input(char *input)
{
	char	**args;

	if (!has_quote_sign(input))
		return (ft_split(input, ' '));
	substitute_spaces(input, '"');
	substitute_spaces(input, '\'');
	rm_quotes(input);
	args = ft_split(input, ' ');
	restore_subst_space(args);
	return (args);
}
