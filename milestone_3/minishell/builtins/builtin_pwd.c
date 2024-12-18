/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:57:52 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 14:31:06 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	builtin_pwd(char **argv)
{
	int		pos;
	char	curr[PATH_MAX];

	pos = 1;
	if (argv[pos] && argv[pos][0] == '-')
	{
		ft_putendl_fd("invalid syntax", STDERR_FILENO);
		return (1);
	}
	else
	{
		getcwd(curr, PATH_MAX);
		ft_putendl_fd(curr, STDOUT_FILENO);
	}
	return (0);
}
