/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/27 08:24:36 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	init_philo(t_philo **philo, t_data *data)
{
	pthread_mutex_t	*fork;
	int				i;

	fork = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (fork == NULL)
		return (1);
	i = 0;
	while (i < data->philo_count)
		pthread_mutex_init(&fork[i++], NULL);
	i = 0;
	while (i < data->philo_count)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].last_meal_time = data->sim_start;
		(*philo)[i].meal_count = 0;
		(*philo)[i].left_fork = i;
		if (i - 1 < 0)
			(*philo)[i].right_fork = data->philo_count - 1;
		else
			(*philo)[i].right_fork = i - 1;
		(*philo)[i].fork = fork;
		(*philo)[i].data = data;
		i++;
	}
	return (0);
}

int	init_data_mutexes(t_data **data)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = malloc(sizeof(pthread_mutex_t) * TOTAL);
	if (mutex == NULL)
		return (1);
	i = 0;
	while (i < TOTAL)
		pthread_mutex_init(&mutex[i++], NULL);
	(*data)->mutex = mutex;
	return (0);
}

int	init_data(t_data **data, int argc, char **argv)
{
	(*data)->sim_start = get_time();
	(*data)->philo_count = ft_atol(argv[1]);
	(*data)->time_to_die = ft_atol(argv[2]);
	(*data)->time_to_eat = ft_atol(argv[3]);
	(*data)->time_to_sleep = ft_atol(argv[4]);
	(*data)->time_to_think = 0;
	if (((*data)->philo_count % 2) && ((*data)->time_to_eat
			> (*data)->time_to_sleep))
		(*data)->time_to_think = 1 + ((*data)->time_to_eat
				- (*data)->time_to_sleep);
	if (argc == 6)
		(*data)->meals_required = ft_atol(argv[5]);
	else
		(*data)->meals_required = -1;
	(*data)->is_done = 0;
	(*data)->has_died = 0;
	if (init_data_mutexes(data))
		return (1);
	return (0);
}

int	init_all(t_philo **philo, t_data **data, int argc, char **argv)
{
	*data = malloc(sizeof(t_data));
	if (*data == NULL)
		return (1);
	(*data)->mutex = NULL;
	if (init_data(data, argc, argv) != 0)
		return (1);
	*philo = malloc(sizeof(t_philo) * (*data)->philo_count);
	if (*philo == NULL)
		return (1);
	(*philo)->fork = NULL;
	if (init_philo(philo, *data) != 0)
		return (1);
	return (0);
}
