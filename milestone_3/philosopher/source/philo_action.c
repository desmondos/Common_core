/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/27 07:45:54 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	start_eating(t_philo *phi)
{
	pthread_mutex_lock(&phi->fork[ft_min(phi->left_fork, phi->right_fork)]);
	print_action(phi, "has taken a fork");
	if (phi->left_fork == phi->right_fork)
	{
		pthread_mutex_unlock(&phi->fork[ft_min(phi->left_fork,
				phi->right_fork)]);
		return (1);
	}
	pthread_mutex_lock(&phi->fork[ft_max(phi->left_fork, phi->right_fork)]);
	print_action(phi, "has taken a fork");
	print_action(phi, "is eating");
	return (0);
}

int	finish_eating(t_philo *phi)
{
	print_action(phi, "is sleeping");
	pthread_mutex_unlock(&phi->fork[ft_max(phi->left_fork,
			phi->right_fork)]);
	pthread_mutex_unlock(&phi->fork[ft_min(phi->left_fork,
			phi->right_fork)]);
	correct_usleep(phi->data->time_to_sleep);
	return (0);
}

int	eating(t_philo *phi)
{
	if (start_eating(phi) != 0)
		return (1);
	pthread_mutex_lock(&phi->data->mutex[MEAL]);
	phi->last_meal_time = get_time();
	phi->meal_count++;
	pthread_mutex_unlock(&phi->data->mutex[MEAL]);
	if (check_done(phi))
	{
		finish_eating(phi);
		return (1);
	}
	correct_usleep(phi->data->time_to_eat);
	finish_eating(phi);
	return (0);
}

void	*simulation(void *arg)
{
	t_philo	*phi;

	phi = (t_philo *)arg;
	if (phi->id % 2 == 0)
	{
		print_action(phi, "is thinking");
		correct_usleep(phi->data->time_to_eat);
	}
	while (1)
	{
		if (check_died(phi))
			break ;
		if (eating(phi) != 0)
			break ;
		print_action(phi, "is thinking");
		correct_usleep(phi->data->time_to_think);
	}
	return (NULL);
}
