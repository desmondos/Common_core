/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/22 16:04:16 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	check_args(int argc, char **argv)
{
	if (argc < 5)
	{
		write (2, "Error: Too few arguments.\n", 26);
		return (FAILURE);
	}
	if (argc > 6)
	{
		write (2, "Error: Too many arguments.\n", 27);
		return (FAILURE);
	}
	while (argc-- > 1)
	{
		if (is_digit (argv[argc]) == FALSE)
		{
			write (2, "Error: Invalid character.\n", 26);
			return (FAILURE);
		}
		if (ft_atol (argv[argc]) > INT_MAX || ft_atol (argv[argc]) < 0)
		{
			write (2, "Error: Out of range value.\n", 27);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	check_valid_args(int ac, char **av)
{
	if ((ac == 6 && ft_atol (av[5]) == 0))
		return (TRUE);
	if (ft_atol (av[1]) == 0)
		return (TRUE);
	return (FALSE);
}
