/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:00:44 by candriam          #+#    #+#             */
/*   Updated: 2024/12/12 14:21:48 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_create_env_node(char *data, t_env **head)
{
	t_env	*new;
	t_env	*curr;

	new = malloc(sizeof(t_env));
	if (!new)
		return ;
	new->data = ft_strdup(data);
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

char	*get_var_value(char *data)
{
	int	i;

	i = 0;
	while (data[i] != '=' && data[i])
		i++;
	if (data[i] == '\0')
		return (NULL);
	return (&data[i + 1]);
}

char	*get_var_name(char *data)
{
	int		i;

	i = 0;
	while (data[i] != '=' && data[i])
		i++;
	return (ft_substr(data, 0, i));
}

size_t	ft_env_len(t_env *env)
{
	t_env	*curr;
	size_t	len;

	len = 0;
	curr = env;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}
