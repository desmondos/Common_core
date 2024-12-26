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

void	create_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->num_philos)
	{
		philos[i].start_time = get_time();
		pthread_create(&philos[i].thread, NULL,
			philo_routine, &philos[i]);
		pthread_detach(philos[i].thread);
		i++;
	}
}
