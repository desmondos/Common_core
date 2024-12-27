/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/27 08:00:17 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	data = NULL;
	philo = NULL;
	if (check_args(argc, argv) != 0)
	{
		free_all(philo, data);
		return (EXIT_FAILURE);
	}
	if (check_valid_args(argc, argv))
	{
		free_all(philo, data);
		return (EXIT_SUCCESS);
	}
	if (init_all(&philo, &data, argc, argv) != 0 || simulator(philo, data) != 0)
	{
		free_all(philo, data);
		return (EXIT_FAILURE);
	}
	free_all(philo, data);
	return (EXIT_SUCCESS);
}
