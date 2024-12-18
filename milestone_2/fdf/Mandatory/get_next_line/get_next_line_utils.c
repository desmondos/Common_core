/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:19:10 by candriam          #+#    #+#             */
/*   Updated: 2024/03/29 10:27:46 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_is_newline(t_data *list)
{
	int	pos_data;

	if (!list)
		return (0);
	while (list)
	{
		pos_data = 0;
		while (list->data[pos_data])
		{
			if (list->data[pos_data] == '\n')
				return (1);
			pos_data++;
		}
		list = list->next;
	}
	return (0);
}

int	ft_newline_len(t_data *list)
{
	int	pos;
	int	length;

	if (!list)
		return (0);
	length = 0;
	while (list)
	{
		pos = 0;
		while (list->data[pos])
		{
			if (list->data[pos] == '\n')
			{
				length++;
				return (length);
			}
			pos++;
			length++;
		}
		list = list->next;
	}
	return (length);
}

t_data	*ft_is_lastlst(t_data *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_subcpy(t_data *list, char *sub)
{
	int	pos_data;
	int	pos_sub;

	pos_sub = 0;
	if (!list)
		return ;
	while (list)
	{
		pos_data = 0;
		while (list->data[pos_data])
		{
			if (list->data[pos_data] == '\n')
			{
				sub[pos_sub++] = '\n';
				sub[pos_sub] = '\0';
				return ;
			}
			sub[pos_sub++] = list->data[pos_data++];
		}
		list = list->next;
	}
	sub[pos_sub] = '\0';
}

void	ft_clean_alloc(t_data **list, t_data *new_list, char *sub)
{
	t_data	*stash;
	int		pos_data;

	if (*list == NULL)
		return ;
	while (*list)
	{
		stash = (*list)->next;
		free((*list)->data);
		free(*list);
		*list = stash;
	}
	*list = NULL;
	pos_data = 0;
	if (new_list->data[pos_data])
		*list = new_list;
	else
	{
		free(sub);
		free(new_list);
	}
}
