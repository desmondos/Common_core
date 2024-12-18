/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:56:00 by candriam          #+#    #+#             */
/*   Updated: 2024/08/02 12:18:23 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	char	*merged_arg;

	a = NULL;
	if (argc == 1)
		return (1);
	check_argument(argc, argv);
	if (argc == 2)
		argv = ft_split(argv[1], 32);
	else if (argc > 2)
	{
		merged_arg = arg_merge(argc, argv);
		if (!merged_arg)
			return (1);
		argv = ft_split(merged_arg, 32);
		free(merged_arg);
	}
	if (initialize_stack(&a, argv + 1) == 1)
		free_puterror_exit(&a, argv);
	main_sort(a);
	free_arg(argv);
	return (0);
}

void	check_argument(int ac, char **av)
{
	int	av_pos;

	av_pos = 1;
	while (av_pos <= ac - 1)
	{
		if (ac >= 2 && ((av[av_pos][0] == 32 && !av[av_pos][1])
			|| !av[av_pos][0]))
			puterror_exit();
		av_pos++;
	}
}
