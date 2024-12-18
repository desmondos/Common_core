/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:03:48 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 16:48:26 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_redirect_char(char c)
{
	return (c == '>' || c == '<');
}

int	skip_spaces(char *input, int i)
{
	while (input[i] && isspace(input[i]))
		i++;
	return (i);
}

int	is_blank(char *input)
{
	int	pos;

	pos = 0;
	if (!input)
		return (1);
	while (input[pos])
	{
		if (input[pos] != ' ')
			return (0);
		pos++;
	}
	return (1);
}

int	handle_redirect(char *input, int i)
{
	char	redirect;

	redirect = input[i];
	i++;
	if (input[i] == redirect)
		i++;
	i = skip_spaces(input, i);
	if (is_redirect_char(input[i]) || input[i] == '\0')
	{
		syn_error("<");
		return (-1);
	}
	return (i);
}

int	check_hd_syntax(char *input)
{
	if (input[0] == '<' && input[1] == '<')
		return (syn_error("<<"));
	else if (input[0] == '>' && input[1] == '>')
		return (syn_error(">>"));
	input[1] = '\0';
	return (syn_error(input));
}
