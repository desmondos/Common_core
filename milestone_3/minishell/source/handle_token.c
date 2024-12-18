/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:32:51 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/12 16:24:42 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_special_char(char c)
{
	if (c == '\0' || c == 32 || c == '\'' || c == '"' || c == '|' || c == '>')
		return (1);
	return (0);
}

int	is_dir(char *input)
{
	struct stat	path_stat;

	if (stat(input, &path_stat) != 0)
		return (0);
	if (S_ISDIR(path_stat.st_mode))
	{
		if (*input == '.')
			input++;
		if (*input == '.')
			input++;
		if (*input == '/')
			return (1);
	}
	return (0);
}

int	is_path(char *input)
{
	if (*input == '.')
		input++;
	if (*input == '.')
		input++;
	if (*input == '/')
		return (1);
	return (0);
}
