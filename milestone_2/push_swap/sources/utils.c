/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:40:44 by candriam          #+#    #+#             */
/*   Updated: 2024/08/02 10:24:28 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	str_to_long(const char *nptr)
{
	int		pos;
	int		is_neg;
	long	data;

	pos = 0;
	is_neg = 1;
	data = 0;
	while (nptr[pos] == 32 || (nptr[pos] >= 9 && nptr[pos] <= 13))
		pos++;
	if (nptr[pos] == '-')
	{
		is_neg *= -1;
		pos++;
	}
	else if (nptr[pos] == '+')
		pos++;
	while (nptr[pos])
	{
		if (!(nptr[pos] >= 48 && nptr[pos] <= 57))
			return (2147483648);
		else
			data = data * 10 + (nptr[pos++] - 48);
	}
	return (is_neg * data);
}

void	ft_rot_a(t_list **a, t_list *top)
{
	while (*a != top)
	{
		if (top->pre_mid)
			ft_ra(a);
		else
			ft_rra(a);
	}
}

void	ft_rot_b(t_list **b, t_list *top)
{
	while (*b != top)
	{
		if (top->pre_mid)
			ft_rb(b);
		else
			ft_rrb(b);
	}
}

t_list	*get_cheapest_node(t_list *stack)
{
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	perform_moves(t_list **a, t_list **b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest_node(*b);
	if (cheapest_node == NULL || cheapest_node->target == NULL)
		return ;
	if (cheapest_node->pre_mid && cheapest_node->target->pre_mid)
	{
		while (*b != cheapest_node && *a != cheapest_node->target)
			ft_rr(a, b);
	}
	else if (!(cheapest_node->pre_mid) && !(cheapest_node->target->pre_mid))
	{
		while (*b != cheapest_node && *a != cheapest_node->target)
			ft_rrr(a, b);
	}
	ft_rot_b(b, cheapest_node);
	ft_rot_a(a, cheapest_node->target);
	ft_pa(a, b);
}
