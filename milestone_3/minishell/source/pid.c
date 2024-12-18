/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:32:51 by frajaona          #+#    #+#             */
/*   Updated: 2024/12/12 15:16:18 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_child(char **cmds, t_env **env)
{
	rl_clear_history();
	free_ft_env(env);
	ft_free_array(cmds);
	close_all_fds();
	exit(EXIT_FAILURE);
}

int	*init_c_pid(char **cmds)
{
	int		*c_pid;
	size_t	len;

	len = sizeof(int) * (ft_len(cmds) + 1);
	c_pid = malloc(len);
	if (!c_pid)
		return (NULL);
	ft_bzero(c_pid, len);
	return (c_pid);
}
