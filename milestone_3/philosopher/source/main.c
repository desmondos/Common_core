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
	t_data	*data;
	t_philo	*philo;

	data = NULL;
	philo = NULL;
	if (check_args(argc, argv) != SUCCESS)
		return ((void)free_all(philo, data), EXIT_FAILURE);
	if (check_valid_args(argc, argv))
		return ((void)free_all(philo, data), EXIT_SUCCESS);
	if (init_all(&philo, &data, argc, argv) != SUCCESS)
		return ((void)free_all(philo, data), EXIT_FAILURE);
	if (simulator(philo, data) != SUCCESS)
		return ((void)free_all(philo, data), EXIT_FAILURE);
	return ((void)free_all(philo, data), EXIT_SUCCESS);
}
