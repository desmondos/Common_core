/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:00:44 by candriam          #+#    #+#             */
/*   Updated: 2024/12/13 18:00:00 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*create_ft_env_data(char *var_name, char *var_value)
{
	char	*new_data;
	int		total_length;
	int		i;

	i = 0;
	total_length = ft_strlen(var_name) + ft_strlen(var_value) + 2;
	new_data = malloc(total_length);
	if (!new_data)
		return (NULL);
	while (*var_name)
		new_data[i++] = *var_name++;
	new_data[i++] = '=';
	while (*var_value)
		new_data[i++] = *var_value++;
	new_data[i] = '\0';
	return (new_data);
}

void	handle_ft_env_var(char *var_name, char *var_value, t_env *env)
{
	char	*new_data;

	new_data = create_ft_env_data(var_name, var_value);
	if (!new_data)
		return ;
	add_back(new_data, &env);
	free(new_data);
}

void	update_ft_env(char *var_name, char *var_value, t_env *env)
{
	t_env	*curr;
	char	*new_data;
	int		pos;

	curr = ft_env_var(var_name, env);
	if (!curr)
	{
		new_data = create_ft_env_data(var_name, var_value);
		add_back(new_data, &env);
		free(new_data);
		return ;
	}
	free(curr->data);
	new_data = malloc(sizeof(char) * (ft_strlen(var_name)
				+ ft_strlen(var_value) + 2));
	if (!new_data)
		return ;
	pos = 0;
	while (*var_name)
		new_data[pos++] = *var_name++;
	new_data[pos++] = '=';
	while (*var_value)
		new_data[pos++] = *var_value++;
	new_data[pos] = '\0';
	curr->data = new_data;
}

void	free_ft_env(t_env **env)
{
	t_env	*curr;
	t_env	*new;

	curr = *env;
	while (curr)
	{
		free(curr->data);
		new = curr->next;
		free(curr);
		curr = new;
	}
	env = NULL;
}
