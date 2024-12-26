/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/26 07:43:49 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	destroy_mutexes(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_nb)
		pthread_mutex_destroy (&philo->fork[i++]);
	i = 0;
	while (i < M_NUM)
		pthread_mutex_destroy (&data->mutex[i++]);
}

int	all_done(t_philo *philo, t_data *data)
{
	int	i;
	int	done;
	int	meals_count;

	if (data->must_eat == -1)
		return (FALSE);
	i = -1;
	done = -1;
	while (++i < data->philo_nb)
	{
		pthread_mutex_lock (&philo->data->mutex[MEALS]);
		meals_count = philo[i].meals_counter;
		pthread_mutex_unlock (&philo->data->mutex[MEALS]);
		if (meals_count >= data->must_eat)
			if (++done == data->philo_nb - 1)
				return (TRUE);
		usleep (50);
	}
	return (FALSE);
}

int	monitor(t_philo *philo, t_data *data)
{
	int				i;
	long			last_meal;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&data->mutex[MEALS]);
		last_meal = philo[i].last_meal;
		pthread_mutex_unlock(&data->mutex[MEALS]);
		if (last_meal && all_done(philo, data))
		{
			done(data);
			break ;
		}
		if (last_meal && get_abs_time() - last_meal > data->time_to_die)
		{
			died(data);
			print_action(&philo[i], "died");
			break ;
		}
		i = (i + 1) % data->philo_nb;
		usleep (200);
	}
	return (SUCCESS);
}

int	simulator(t_philo *philo, t_data *data)
{
	int			i;
	pthread_t	*th;

	th = malloc (sizeof (pthread_t) * (size_t)data->philo_nb);
	if (th == NULL)
		return (FAILURE);
	i = -1;
	while (++i < data->philo_nb)
	{
		if (pthread_create (&th[i], 0, simulation, (void *)&philo[i]))
		{
			while (i--)
				pthread_join (th[i], NULL);
			return ((void)free (th), FAILURE);
		}
	}
	if (monitor (philo, data) != SUCCESS)
		return ((void)destroy_mutexes (philo, data), (void)free (th),
			FAILURE);
	i = -1;
	while (++i < data->philo_nb)
		if (pthread_join (th[i], NULL))
			return (FAILURE);
	return ((void)destroy_mutexes (philo, data), (void)free (th), SUCCESS);
}
