/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 06:03:48 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 16:13:23 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	invalid_token(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

int	invalid_redirect(char *input)
{
	char	*red_pos;
	char	next_redir;

	next_redir = has_multi_redir(input);
	red_pos = redir_pos(input, next_redir);
	if (!red_pos)
		return (0);
	if (red_pos[0] == '<' && red_pos[1] == '<')
		red_pos += 2;
	else if (red_pos[0] == '>' && red_pos[1] == '>')
		red_pos += 2;
	else
		red_pos++;
	while (*red_pos == 32 || *red_pos == '\t')
		red_pos++;
	if (*red_pos == '\0')
		return (syn_error("newline"));
	if (invalid_token(*red_pos))
		return (check_hd_syntax(red_pos));
	return (invalid_redirect(red_pos));
}
