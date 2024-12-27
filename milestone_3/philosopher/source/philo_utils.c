/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/27 08:49:10 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->data->mutex[PRINT]);
	if (ft_strncmp(action, "died", 4) == 0 || (!check_died(philo)
			&& !check_done(philo)))
		printf("%lu %d %s\n", get_relative_time(philo->data->sim_start),
			philo->id, action);
	pthread_mutex_unlock(&philo->data->mutex[PRINT]);
}

void	died(t_data *data)
{
	pthread_mutex_lock(&data->mutex[DIED]);
	data->has_died = 1;
	pthread_mutex_unlock(&data->mutex[DIED]);
}

void	done(t_data *data)
{
	pthread_mutex_lock(&data->mutex[DONE]);
	data->is_done = 1;
	pthread_mutex_unlock(&data->mutex[DONE]);
}

int	check_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex[DIED]);
	if (philo->data->has_died)
	{
		pthread_mutex_unlock(&philo->data->mutex[DIED]);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex[DIED]);
	return (0);
}

int	check_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex[DONE]);
	if (philo->data->is_done)
	{
		pthread_mutex_unlock(&philo->data->mutex[DONE]);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex[DONE]);
	return (0);
}
