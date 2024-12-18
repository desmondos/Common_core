/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 06:49:06 by candriam          #+#    #+#             */
/*   Updated: 2024/08/02 10:17:26 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_puterror_exit(t_list **stack, char **argv)
{
	free_arg(argv);
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	puterror_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	has_dup(t_list *stack, int input)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->data == input)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_valid_input(char *input)
{
	int	pos;

	pos = 0;
	if ((input[pos] >= 48 && input[pos] <= 57)
		|| (input[pos] == '-' || input[pos] == '+'))
		return (0);
	if ((input[pos] == '-' || input[pos] == '+')
		&& (input[pos + 1] >= 48 && input[pos + 1] <= 57))
		return (0);
	while (input[pos++])
	{
		if ((input[pos] >= 48 && input[pos] <= 57))
			return (0);
	}
	return (1);
}

void	free_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
