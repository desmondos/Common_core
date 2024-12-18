/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:56:00 by candriam          #+#    #+#             */
/*   Updated: 2024/08/02 10:41:26 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculate_len(int ac, char **av)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < ac)
	{
		len += ft_strlen(av[i]) + 1;
		i++;
	}
	return (len);
}

char	*arg_merge(int ac, char **av)
{
	char	*before_merge;
	int		len;
	int		i;

	len = calculate_len(ac, av);
	before_merge = (char *)malloc(sizeof(char) * (len + 1));
	if (!before_merge)
		return (NULL);
	before_merge[0] = '\0';
	i = 1;
	while (i < ac)
	{
		ft_strcat(before_merge, av[i]);
		if (i < ac - 1)
			ft_strcat(before_merge, " ");
		i++;
	}
	return (before_merge);
}

int	initialize_stack(t_list **stack, char *argv[])
{
	long	input;
	int		pos;

	pos = 0;
	while (argv[pos])
	{
		if (is_valid_input(argv[pos]))
			return (1);
		input = str_to_long(argv[pos]);
		if (input > INT_MAX || input < INT_MIN)
			return (1);
		if (has_dup(*stack, (int)input))
			return (1);
		append_to_stack(stack, (int)input);
		pos++;
	}
	return (0);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr_dest;

	ptr_dest = dest;
	while (*ptr_dest)
		ptr_dest++;
	while (*src)
	{
		*ptr_dest = *src;
		ptr_dest++;
		src++;
	}
	*ptr_dest = '\0';
	return (dest);
}

void	main_sort(t_list *a)
{
	t_list	*b;

	b = NULL;
	if (is_sorted(a) == false)
	{
		if (get_stack_length(a) == 2)
			ft_sa(&a);
		else if (get_stack_length(a) == 3)
			easy_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
