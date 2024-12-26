/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/26 07:40:56 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	start_eating(t_philo *self)
{
	pthread_mutex_lock(&self->fork[ft_min(self->left_fork, self->right_fork)]);
	print_action(self, "has taken a fork");
	if (self->left_fork == self->right_fork)
	{
		pthread_mutex_unlock(&self->fork[ft_min(self->left_fork,
				self->right_fork)]);
		return (FAILURE);
	}
	pthread_mutex_lock(&self->fork[ft_max(self->left_fork, self->right_fork)]);
	print_action(self, "has taken a fork");
	print_action(self, "is eating");
	return (SUCCESS);
}

int	finish_eating(t_philo *self)
{
	print_action(self, "is sleeping");
	pthread_mutex_unlock(&self->fork[ft_max(self->left_fork,
			self->right_fork)]);
	pthread_mutex_unlock(&self->fork[ft_min(self->left_fork,
			self->right_fork)]);
	correct_usleep(self->data->time_to_sleep);
	return (SUCCESS);
}

int	eating(t_philo *self)
{
	if (start_eating(self) != SUCCESS)
		return (FAILURE);
	pthread_mutex_lock(&self->data->mutex[MEALS]);
	self->last_meal = get_abs_time ();
	self->meals_counter++;
	pthread_mutex_unlock(&self->data->mutex[MEALS]);
	if (check_done(self))
	{
		finish_eating (self);
		return (FAILURE);
	}
	correct_usleep (self->data->time_to_eat);
	finish_eating (self);
	return (SUCCESS);
}

void	*simulation(void *arg)
{
	t_philo	*self;

	self = (t_philo *) arg;
	if (self->id % 2 == 0)
	{
		print_action(self, "is thinking");
		correct_usleep(self->data->time_to_eat);
	}
	while (1)
	{
		if (check_died(self))
			break ;
		if (eating (self) != SUCCESS)
			break ;
		print_action(self, "is thinking");
		correct_usleep (self->data->time_to_think);
	}
	return (NULL);
}
