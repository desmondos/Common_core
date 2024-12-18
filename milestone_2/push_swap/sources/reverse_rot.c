/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:14:11 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 08:03:47 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	int		len;

	len = get_stack_length(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last = get_last_node(*stack);
	last->back->next = NULL;
	last->next = *stack;
	last->back = NULL;
	*stack = last;
	last->next->back = last;
}

void	ft_rra(t_list **a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
