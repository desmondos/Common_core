/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:29:03 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 08:21:03 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_list **a, t_list **b)
{
	t_list	*lowest_node;
	int		len_a;

	len_a = get_stack_length(*a);
	if (len_a == 5)
		mid_sort(a, b);
	else
		while (len_a-- > 3)
			ft_pb(b, a);
	easy_sort(a);
	while (*b)
	{
		initialize_nodes(*a, *b);
		perform_moves(a, b);
	}
	setup_pos(*a);
	lowest_node = find_min_node(*a);
	if (lowest_node->pre_mid)
		while (*a != lowest_node)
			ft_ra(a);
	else
		while (*a != lowest_node)
			ft_rra(a);
}

void	setup_pos(t_list *stack)
{
	int	pos;
	int	middle_stack;

	if (!stack)
		return ;
	pos = 0;
	middle_stack = get_stack_length(stack) / 2;
	while (stack)
	{
		stack->cur_pos = pos;
		if (pos <= middle_stack)
			stack->pre_mid = true;
		else
			stack->pre_mid = false;
		stack = stack->next;
		pos++;
	}
}

void	setup_target(t_list *a, t_list *b)
{
	t_list	*cur_a;
	t_list	*target;
	long	match_data;

	while (b)
	{
		match_data = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->data > b->data && cur_a->data < match_data)
			{
				match_data = cur_a->data;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (LONG_MAX == match_data)
			b->target = find_min_node(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	id_cheapest_node(t_list *b)
{
	t_list	*cheapest_node;
	long	cheapest_move_cost;

	if (!b)
		return ;
	cheapest_move_cost = LONG_MAX;
	while (b)
	{
		if (b->move < cheapest_move_cost)
		{
			cheapest_move_cost = b->move;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->is_cheapest = true;
}

void	set_move_costs(t_list *a, t_list *b)
{
	int		length_a;
	int		length_b;
	int		move_a;
	int		move_b;

	length_a = get_stack_length(a);
	length_b = get_stack_length(b);
	while (b)
	{
		move_a = b->target->cur_pos;
		move_b = b->cur_pos;
		if (!(b->target->pre_mid))
			move_a = length_a - (b->target->cur_pos);
		if (!b->pre_mid)
			move_b = length_b - b->cur_pos;
		b->move = move_a + move_b;
		if (b->target->pre_mid && b->pre_mid)
			b->move -= min(move_a, move_b);
		else if (!b->target->pre_mid && !b->pre_mid)
			b->move -= min(move_a, move_b);
		b = b->next;
	}
}
