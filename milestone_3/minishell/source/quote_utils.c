/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:04:48 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 15:26:32 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_quote(char c)
{
	return (c == '"' || c == '\'');
}

int	has_quote(char *input)
{
	int	pos;

	pos = 0;
	if (!input)
		return (0);
	while (input && input[pos])
	{
		if (is_quote(input[pos]))
			return (1);
		pos++;
	}
	return (0);
}

int	has_quote_sign(char *str)
{
	if (!str)
		return (0);
	while (str && *str)
	{
		if (is_quote(*str))
			return (1);
		str++;
	}
	return (0);
}

void	rm_quotes(char *str)
{
	char	last_opened;

	last_opened = 0;
	while (*str && !last_opened)
	{
		if (*str == '\'' || *str == '"')
		{
			last_opened = *str;
			ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
		}
		else
			str++;
	}
	while (*str && last_opened)
	{
		if (*str && *str == last_opened)
		{
			last_opened = 0;
			ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
		}
		else
			str++;
	}
	if (*str)
		return (rm_quotes(str));
}
