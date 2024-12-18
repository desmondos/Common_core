/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:00:44 by candriam          #+#    #+#             */
/*   Updated: 2024/12/18 11:03:57 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*ft_copy_environs(char **environ)
{
	t_env	*head;
	int		i;
	char	*temp;

	head = NULL;
	i = 0;
	while (environ[i] != NULL)
	{
		add_back(environ[i], &head);
		i++;
	}
	if (!ft_env_var("OLDPWD", head))
		add_back("OLDPWD", &head);
	temp = ft_strjoin("__HOME=", ft_env_val("HOME", head));
	add_back(temp, &head);
	free(temp);
	return (head);
}

t_env	*ft_env_var(char *var_name, t_env *env)
{
	t_env	*curr;
	char	*curr_v_name;
	int		len;

	curr = env;
	len = ft_strlen(var_name);
	while (curr)
	{
		curr_v_name = get_var_name(curr->data);
		if (curr_v_name && ft_strncmp(curr_v_name, var_name, len + 1) == 0)
		{
			free(curr_v_name);
			return (curr);
		}
		free(curr_v_name);
		curr = curr->next;
	}
	return (NULL);
}

void	add_back(char *data, t_env **node)
{
	struct s_env	*new;
	struct s_env	*curr;

	new = malloc(sizeof(struct s_env));
	new->data = ft_strdup(data);
	new->next = NULL;
	if (!*node)
	{
		*node = new;
		return ;
	}
	curr = *node;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

char	*ft_env_val(char *var_name, t_env *env)
{
	t_env	*curr;

	curr = ft_env_var(var_name, env);
	if (!curr)
		return (NULL);
	return (get_var_value(curr->data));
}

char	**create_ft_environ(t_env *env)
{
	int		i;
	char	**environ;
	t_env	*curr;

	environ = malloc(sizeof(char *) * (ft_env_len(env) + 1));
	curr = env;
	i = 0;
	while (curr)
	{
		environ[i] = ft_strdup(curr->data);
		i++;
		curr = curr->next;
	}
	environ[i] = NULL;
	return (environ);
}
