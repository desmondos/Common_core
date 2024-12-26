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

void	print_action(t_philo *philo, char *a)
{
	pthread_mutex_lock (&philo->data->mutex[PRINT]);
	if (*a == 'd' || (!check_died (philo) && !check_done (philo)))
		printf("%lu %d %s\n", get_rel_time(philo->data->simbegin),
			philo->id, a);
	pthread_mutex_unlock (&philo->data->mutex[PRINT]);
}

void	died(t_data *data)
{
	pthread_mutex_lock (&data->mutex[DIED]);
	data->died = TRUE;
	pthread_mutex_unlock (&data->mutex[DIED]);
}

void	done(t_data *data)
{
	pthread_mutex_lock (&data->mutex[DONE]);
	data->done = TRUE;
	pthread_mutex_unlock (&data->mutex[DONE]);
}

int	check_died(t_philo *philo)
{
	pthread_mutex_lock (&philo->data->mutex[DIED]);
	if (philo->data->died)
	{
		pthread_mutex_unlock (&philo->data->mutex[DIED]);
		return (TRUE);
	}
	pthread_mutex_unlock (&philo->data->mutex[DIED]);
	return (FALSE);
}

int	check_done(t_philo *philo)
{
	pthread_mutex_lock (&philo->data->mutex[DONE]);
	if (philo->data->done)
	{
		pthread_mutex_unlock (&philo->data->mutex[DONE]);
		return (TRUE);
	}
	pthread_mutex_unlock (&philo->data->mutex[DONE]);
	return (FALSE);
}
