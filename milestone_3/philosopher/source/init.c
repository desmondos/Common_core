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

int	init_philo(t_philo **philo, t_data *data)
{
	pthread_mutex_t	*fork;
	int				i;

	fork = malloc (sizeof (pthread_mutex_t) * ((size_t)data->philo_nb));
	if (fork == NULL)
		return (FAILURE);
	i = 0;
	while (i < data->philo_nb)
		pthread_mutex_init (&fork[i++], NULL);
	i = 0;
	while (i < data->philo_nb)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].last_meal = data->simbegin;
		(*philo)[i].meals_counter = 0;
		(*philo)[i].left_fork = i;
		if (i - 1 < 0)
			(*philo)[i].right_fork = data->philo_nb - 1;
		else
			(*philo)[i].right_fork = i - 1;
		(*philo)[i].fork = fork;
		(*philo)[i].data = data;
		i++;
	}
	return (SUCCESS);
}

int	init_data_mutexes(t_data **data)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = malloc (sizeof (pthread_mutex_t) * ((size_t)M_NUM));
	if (mutex == NULL)
		return (FAILURE);
	i = 0;
	while (i < M_NUM)
		pthread_mutex_init (&mutex[i++], NULL);
	(*data)->mutex = mutex;
	return (SUCCESS);
}

int	init_data(t_data **data, int ac, char **av)
{
	(*data)->simbegin = get_abs_time ();
	(*data)->philo_nb = (int)ft_atol (av[1]);
	(*data)->time_to_die = (int)ft_atol (av[2]);
	(*data)->time_to_eat = (int)ft_atol (av[3]);
	(*data)->time_to_sleep = (int)ft_atol (av[4]);
	(*data)->time_to_think = 0;
	if (((*data)->philo_nb % 2) && ((*data)->time_to_eat
			> (*data)->time_to_sleep))
		(*data)->time_to_think = 1 + ((*data)->time_to_eat
				- (*data)->time_to_sleep);
	if (ac == 5)
		(*data)->must_eat = -1;
	if (ac == 6)
		(*data)->must_eat = (int)ft_atol (av[5]);
	(*data)->done = FALSE;
	(*data)->died = FALSE;
	if (init_data_mutexes (data))
		return (FAILURE);
	return (SUCCESS);
}

int	init_all(t_philo **philo, t_data **data, int ac, char **av)
{
	*data = (t_data *)malloc (sizeof (t_data));
	if (*data == NULL)
		return (FAILURE);
	(*data)->mutex = NULL;
	if (init_data (data, ac, av) != SUCCESS)
		return (FAILURE);
	*philo = (t_philo *)malloc (sizeof (t_philo) * (size_t)(*data)->philo_nb);
	if (*philo == NULL)
		return (FAILURE);
	(*philo)->fork = NULL;
	if (init_philo (philo, *data) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
