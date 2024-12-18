/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:15:47 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 08:04:01 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*last;
	int		len;

	len = get_stack_length(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last = get_last_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->back = NULL;
	last->next->back = last;
	last->next->next = NULL;
}

void	ft_ra(t_list **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}

void	rot_all(t_list **a, t_list **b, t_list *cheap)
{
	while ((*a)->pre_mid && cheap->pre_mid)
		ft_rr(a, b);
	while (!(*a)->pre_mid && !cheap->pre_mid)
		ft_rrr(a, b);
}
