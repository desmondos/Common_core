/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:25:06 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 16:45:37 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_valid_varname(char *name)
{
	if (!ft_is_alpha(*name))
		return (0);
	while (*name)
	{
		if (!is_var_name(*name))
			return (0);
		name++;
	}
	return (1);
}

char	*skip_single_quotes(char *input)
{
	input++;
	while (*input && *input != '\'')
		input++;
	if (*input == '\'')
		input++;
	return (input);
}

char	*handle_double_quotes(char *input)
{
	input++;
	while (*input && *input != '\"')
	{
		if (*input == '$' && is_var_name(input[1]))
			return (input);
		input++;
	}
	if (*input == '\"')
		input++;
	return (input);
}

char	*var_pos(char *input)
{
	while (*input)
	{
		if (*input == '\'')
			input = skip_single_quotes(input);
		else if (*input == '\"')
			input = handle_double_quotes(input);
		else if (*input == '$' && is_var_name(input[1]))
			return (input);
		else
			input++;
	}
	return (NULL);
}
