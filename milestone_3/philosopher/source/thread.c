/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/27 08:31:55 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	destroy_mutexes(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_count)
		pthread_mutex_destroy(&philo->fork[i++]);
	i = 0;
	while (i < TOTAL)
		pthread_mutex_destroy(&data->mutex[i++]);
}

int	all_done(t_philo *philo, t_data *data)
{
	int	i;
	int	done;
	int	meal_count;

	if (data->meals_required == -1)
		return (0);
	i = -1;
	done = -1;
	while (++i < data->philo_count)
	{
		pthread_mutex_lock(&philo->data->mutex[MEAL]);
		meal_count = philo[i].meal_count;
		pthread_mutex_unlock(&philo->data->mutex[MEAL]);
		if (meal_count >= data->meals_required)
			if (++done == data->philo_count - 1)
				return (1);
		usleep(50);
	}
	return (0);
}

int	monitor(t_philo *philo, t_data *data)
{
	int				i;
	long			last_meal;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&data->mutex[MEAL]);
		last_meal = philo[i].last_meal_time;
		pthread_mutex_unlock(&data->mutex[MEAL]);
		if (last_meal && all_done(philo, data))
		{
			done(data);
			break ;
		}
		if (last_meal && get_time() - last_meal > data->time_to_die)
		{
			died(data);
			print_action(&philo[i], "died");
			break ;
		}
		i = (i + 1) % data->philo_count;
		usleep(1000);
	}
	return (0);
}

static void	free_destroy(t_philo *philo, t_data *data, pthread_t *thread)
{
	destroy_mutexes(philo, data);
	free(thread);
}

int	simulator(t_philo *philo, t_data *data)
{
	int			i;
	pthread_t	*thread;

	thread = safe_malloc(sizeof(pthread_t) * data->philo_count);
	i = -1;
	while (++i < data->philo_count)
	{
		if (pthread_create(&thread[i], 0, simulation, &philo[i]))
		{
			while (i--)
				pthread_join(thread[i], NULL);
			free(thread);
			return (1);
		}
	}
	if (monitor(philo, data) != 0)
		return (free_destroy(philo, data, thread), 1);
	i = -1;
	while (++i < data->philo_count)
		if (pthread_join(thread[i], NULL))
			return (1);
	free_destroy(philo, data, thread);
	return (0);
}
