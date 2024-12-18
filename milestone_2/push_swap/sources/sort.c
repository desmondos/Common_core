/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:59:48 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 08:21:39 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_list *stack)
{
	if (stack == NULL)
		return (1);
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	easy_sort(t_list **stack)
{
	t_list	*highest;

	highest = find_highest_node(*stack);
	if (*stack == highest)
	{
		ft_ra(stack);
		if ((*stack)->data > (*stack)->next->data)
			ft_sa(stack);
	}
	else if ((*stack)->next == highest)
	{
		ft_rra(stack);
		if (is_sorted(*stack))
			return ;
		ft_sa(stack);
	}
	else if ((*stack)->data > (*stack)->next->data)
		ft_sa(stack);
}

void	mid_sort(t_list **a, t_list **b)
{
	while (get_stack_length(*a) > 3)
	{
		initialize_nodes(*a, *b);
		ft_rot_a(a, find_min_node(*a));
		ft_pb(b, a);
	}
}

void	initialize_nodes(t_list *a, t_list *b)
{
	setup_pos(a);
	setup_pos(b);
	setup_target(a, b);
	set_move_costs(a, b);
	id_cheapest_node(b);
}
