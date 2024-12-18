/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:40:54 by candriam          #+#    #+#             */
/*   Updated: 2024/07/30 12:59:04 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_length(t_list *a)
{
	int	len;

	if (!a)
		return (0);
	len = 1;
	while (a->next)
	{
		len++;
		a = a->next;
	}
	return (len);
}

t_list	*find_highest_node(t_list *stack)
{
	long	highest_value;
	t_list	*highest_node;

	if (stack == NULL)
		return (NULL);
	highest_value = INT_MIN;
	while (stack)
	{
		if (stack->data > highest_value)
		{
			highest_value = stack->data;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_list	*find_min_node(t_list *stack)
{
	long	lowest_value;
	t_list	*lowest_node;

	if (stack == NULL)
		return (NULL);
	lowest_value = INT_MAX;
	lowest_node = NULL;
	while (stack)
	{
		if (stack->data < lowest_value)
		{
			lowest_value = stack->data;
			lowest_node = stack;
		}
		else
			stack = stack->next;
	}
	return (lowest_node);
}

int	is_lowest_value(t_list *stack)
{
	int	lowest_value;

	lowest_value = stack->data;
	while (stack)
	{
		if (stack->data < lowest_value)
			lowest_value = stack->data;
		else
			stack = stack->next;
	}
	return (lowest_value);
}

t_list	*get_last_node(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}
