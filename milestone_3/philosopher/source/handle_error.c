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

int	is_valid_args(int argc, char **argv, t_philo *philo)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd("Wrong arguments number", STDERR_FILENO);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (check_pos_nbr(argv[i]) == 0 || ft_atol(argv[i]) <= 0)
			put_error("Error: invalid argument\n");
		i++;
	}
	philo->num_philos = ft_atol(argv[1]);
	philo->time_to_die = ft_atol(argv[2]);
	philo->time_to_eat = ft_atol(argv[3]);
	philo->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		philo->num_must_eat = ft_atol(argv[5]);
	else
		philo->num_must_eat = -1;
	return (1);
}

long	ft_atol(const char *nptr)
{
	long	nb;
	long	is_negative;
	long	i;

	i = 0;
	is_negative = 1;
	nb = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		is_negative = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	if (nb > LONG_MAX)
		put_error("Value superior than INT_MAX");
	return (nb * is_negative);
}

void	to_dead(int id, long time)
{
	ft_putnbr_fd(time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(id, 1);
	write(1, " ", 1);
	write(1, "died", 4);
	write(1, "\n", 1);
}

void	print_action(t_philo *philo, int id, char *action)
{
	long long	timestamp;

	timestamp = get_time() - philo->start_time;
	printf("%lld %d %s\n", timestamp, id, action);
}
