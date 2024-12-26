/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/26 07:55:09 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_philo			*state;

	philos = init_simulation(argc, argv);
	if (!philos)
	{
		ft_putendl_fd("simulation init failed", STDERR_FILENO);
		return (1);
	}
	state = set_data_health(philos);
	if (!state)
	{
		ft_putendl_fd("data health init failed", STDERR_FILENO);
		return (1);
	}
	philo_to_data(philos, state);
	create_threads(philos);
	pthread_create(&state->thread, NULL, check_philos_state, state);
	pthread_join(state->thread, NULL);
	free_all(philos, state);
	return (0);
}
