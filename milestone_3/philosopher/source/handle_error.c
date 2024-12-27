/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/27 06:44:57 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}

int	check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd("Error: Too few or too many arguments.", STDERR_FILENO);
		return (1);
	}
	while (argc-- > 1)
	{
		if (is_digit(argv[argc]) == 0)
		{
			ft_putendl_fd("Error: Invalid argument.", STDERR_FILENO);
			return (1);
		}
		if (ft_atol(argv[argc]) > INT_MAX || ft_atol(argv[argc]) < 0)
		{
			ft_putendl_fd("Error: Out of range value.", STDERR_FILENO);
			return (1);
		}
	}
	return (0);
}

int	check_valid_args(int argc, char **argv)
{
	if ((argc == 6 && ft_atol(argv[5]) == 0))
		return (1);
	if (ft_atol(argv[1]) == 0)
		return (1);
	return (0);
}
