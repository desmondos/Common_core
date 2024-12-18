/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:29:39 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 08:03:27 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(t_list **source, t_list **target)
{
	t_list	*push_elem;

	if (!*target)
		return ;
	push_elem = *target;
	*target = (*target)->next;
	if (*target)
		(*target)->back = NULL;
	push_elem->back = NULL;
	if (!*source)
	{
		*source = push_elem;
		push_elem->next = NULL;
	}
	else
	{
		push_elem->next = *source;
		push_elem->next->back = push_elem;
		*source = push_elem;
	}
}

void	ft_pa(t_list **a, t_list **b)
{
	ft_push(a, b);
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **b, t_list **a)
{
	ft_push(b, a);
	write(1, "pb\n", 3);
}
