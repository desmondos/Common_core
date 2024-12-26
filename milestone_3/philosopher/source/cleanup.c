/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/22 17:35:51 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	free_all(t_philo *philos, t_philo *state)
{
	int	i;

	i = 0;
	ft_usleep(philos->time_to_die + philos->time_to_eat
		+ philos->time_to_sleep + 100);
	while (i < philos->num_philos)
	{
		pthread_mutex_destroy(&philos[i].forks[i]);
		i++;
	}
	pthread_mutex_destroy(state->mutex);
	free(philos->forks);
	free(philos->meals_eaten);
	free(philos->last_meal_time);
	free(philos->mutex);
	free(philos);
	free(state);
}
