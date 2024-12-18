/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:32:41 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 08:26:28 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	append_to_stack(t_list **stack, int input)
{
	t_list	*new_node;
	t_list	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_list));
	if (!(new_node))
		return ;
	new_node->next = NULL;
	new_node->data = input;
	new_node->back = NULL;
	new_node->target = NULL;
	new_node->is_cheapest = 0;
	new_node->pre_mid = 0;
	if (!(*stack))
		*stack = new_node;
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = new_node;
		new_node->back = last_node;
	}
}

void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*next_node;

	if (!stack || !*stack)
		return ;
	next_node = *stack;
	while (next_node)
	{
		current = next_node;
		next_node = current->next;
		free(current);
	}
	*stack = NULL;
}
