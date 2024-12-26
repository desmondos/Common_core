/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/22 16:10:55 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

t_philo	*init_simulation(int argc, char **argv)
{
	t_philo	*philo_init;
	t_philo	*philo;

	philo = safe_malloc(sizeof(t_philo));
	if (is_valid_args(argc, argv, philo) != 1)
		return (NULL);
	philo_init = init_philo(philo);
	if (!philo_init)
		return (NULL);
	return (philo_init);
}

t_philo	*init_philo(t_philo *philo)
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	long long		*last_meal_time;

	philos = safe_malloc(sizeof(t_philo) * philo->num_philos);
	forks = init_forks(philo->num_philos);
	last_meal_time = init_last_meal_time(philo->num_philos);
	init_all_data(philos, philo, forks, last_meal_time);
	return (philos);
}

pthread_mutex_t	*init_forks(int num_philos)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = safe_malloc(sizeof(pthread_mutex_t) * num_philos);
	while (i < num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

long long	*init_last_meal_time(int num_philo)
{
	int			i;
	long long	*last_meal_time;

	i = 0;
	last_meal_time = safe_malloc(sizeof(long long) * num_philo);
	while (i < num_philo)
	{
		last_meal_time[i] = get_time();
		i++;
	}
	return (last_meal_time);
}

void	init_all_data(t_philo *philos, t_philo *philo,
				pthread_mutex_t *num_forks, long long *last_meal_time)
{
	int		i;
	long	*meals;

	meals = safe_malloc(sizeof(long) * philo->num_philos);
	memset(meals, 0, sizeof(int) * philo->num_philos);
	i = 0;
	while (i < philo->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = meals;
		philos[i].time_to_die = philo->time_to_die;
		philos[i].time_to_eat = philo->time_to_eat;
		philos[i].time_to_sleep = philo->time_to_sleep;
		philos[i].num_must_eat = philo->num_must_eat;
		philos[i].last_meal_time = last_meal_time;
		philos[i].num_forks = philo->num_philos;
		philos[i].num_philos = philo->num_philos;
		philos[i].forks = num_forks;
		i++;
	}
	free(philo);
}
