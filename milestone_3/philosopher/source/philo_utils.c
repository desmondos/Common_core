/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/26 07:51:38 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

t_philo	*set_data_health(t_philo *philos)
{
	t_philo	*data;

	data = malloc(sizeof(t_philo));
	data->id = 0;
	data->meals_eaten = philos->meals_eaten;
	data->time_to_die = philos->time_to_die;
	data->time_to_eat = philos->time_to_eat;
	data->time_to_sleep = philos->time_to_sleep;
	data->num_must_eat = philos->num_must_eat;
	data->last_meal_time = philos->last_meal_time;
	data->num_forks = philos->num_philos;
	data->num_philos = philos->num_philos;
	data->forks = NULL;
	data->mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->mutex, NULL);
	return (data);
}

void	philo_to_data(t_philo *philos, t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		philos[i].mutex = data->mutex;
		i++;
	}
	data->start_time = get_time();
}

bool	check_meals_eaten(t_philo *data)
{
	int	i;

	i = 0;
	if (data->num_must_eat == -1)
		return (true);
	while (i < data->num_philos)
	{
		pthread_mutex_lock(data->mutex);
		if (data->meals_eaten[i] < data->num_must_eat)
		{
			pthread_mutex_unlock(data->mutex);
			return (true);
		}
		pthread_mutex_unlock(data->mutex);
		i++;
	}
	pthread_mutex_lock(data->mutex);
	return (false);
}

void	*check_philos_state(void *philos)
{
	t_philo		*data;
	int			i;
	long		time;

	data = (t_philo *)philos;
	i = 0;
	ft_usleep(10);
	while (i < data->num_philos && check_meals_eaten(data))
	{
		pthread_mutex_lock(data->mutex);
		time = get_time() - data->last_meal_time[i];
		pthread_mutex_unlock(data->mutex);
		if (time >= data->time_to_die)
		{
			pthread_mutex_lock(data->mutex);
			to_dead(i + 1, get_time() - data->start_time);
			return (NULL);
		}
		if (i + 1 == data->num_philos)
			i = -1;
		i++;
	}
	return (NULL);
}

void	*philo_routine(void *philo)
{
	t_philo	*philos;

	philos = (t_philo *)philo;
	if (philos->id % 2 == 0)
		ft_usleep(10);
	while (1)
	{
		take_forks(philos);
		eating(philos);
		put_forks(philos);
		sleeping(philos);
		thinking(philos);
	}
}
