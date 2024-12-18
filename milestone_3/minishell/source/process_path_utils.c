/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_path_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:08:30 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/12 15:06:27 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_delimit(char c)
{
	if (c == 32 || c == '<' || c == '>' || c == '\t' || c == '|')
		return (1);
	return (0);
}

int	get_filename_end(char *name)
{
	int	last;

	last = 0;
	while (name[last] && !is_delimit(name[last]))
	{
		if (name[last] == '\'')
		{
			use_memmove(&name[last]);
			while (name[last] && name[last] != '\'')
				last++;
			use_memmove(&name[last]);
		}
		if (name[last] == '"')
		{
			use_memmove(&name[last]);
			while (name[last] && name[last] != '"')
				last++;
			use_memmove(&name[last]);
		}
		else if (name[last] && !is_delimit(name[last]))
			last++;
	}
	return (last);
}

void	use_memmove(char *str)
{
	ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
}

char	*extract_filename(char *str)
{
	int		start;
	int		end;
	char	*filename;
	char	*cmd;

	start = 0;
	use_memmove(str);
	if (str[start] == '>')
		use_memmove(&str[start]);
	while (str[start] == 32 || str[start] == '\t')
		start++;
	end = get_filename_end(&str[start]);
	filename = ft_substr(&str[start], 0, end);
	cmd = &str[start + end];
	ft_memmove(str, cmd, ft_strlen(cmd) + 2);
	return (filename);
}

char	*tmp_name(int hd_nbr)
{
	char	filename[42];
	char	*str_nbr;

	ft_bzero(filename, 42);
	str_nbr = ft_itoa(hd_nbr);
	ft_strlcat(filename, "/tmp/heredoc", 42);
	ft_strlcat(filename, str_nbr, 42);
	free(str_nbr);
	return (ft_strdup(filename));
}
