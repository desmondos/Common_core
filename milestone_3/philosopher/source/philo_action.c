/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/26 07:40:56 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	take_forks(t_philo *philos)
{
	pthread_mutex_lock(&philos->forks[philos->id - 1]);
	if (philos->id == 1)
		pthread_mutex_lock(&philos->forks[philos->num_philos - 1]);
	else
		pthread_mutex_lock(&philos->forks[philos->id - 2]);
	pthread_mutex_lock(philos->mutex);
	print_action(philos, philos->id, "has taken a fork");
	pthread_mutex_unlock(philos->mutex);
}

void	eating(t_philo *philos)
{
	pthread_mutex_lock(philos->mutex);
	print_action(philos, philos->id, "is eating");
	philos->last_meal_time[philos->id - 1] = get_time();
	philos->meals_eaten[philos->id - 1]++;
	pthread_mutex_unlock(philos->mutex);
	ft_usleep(philos->time_to_eat);
}

void	put_forks(t_philo *philos)
{
	pthread_mutex_unlock(&philos->forks[philos->id - 1]);
	if (philos->id == 1)
		pthread_mutex_unlock(&philos->forks[philos->num_philos - 1]);
	else
		pthread_mutex_unlock(&philos->forks[philos->id - 2]);
}

void	sleeping(t_philo *philos)
{
	pthread_mutex_lock(philos->mutex);
	print_action(philos, philos->id, "is sleeping");
	pthread_mutex_unlock(philos->mutex);
	ft_usleep(philos->time_to_sleep);
}

void	thinking(t_philo *philos)
{
	pthread_mutex_lock(philos->mutex);
	print_action(philos, philos->id, "is thinking");
	pthread_mutex_unlock(philos->mutex);
}
