/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/27 08:05:39 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

long	get_time(void)
{
	struct timeval	time;
	long long		sec;
	long long		micro;

	if (gettimeofday(&time, NULL) == -1)
		ft_putendl_fd("Error: GETTIMEOFDAY(2)", STDERR_FILENO);
	sec = time.tv_sec * 1000;
	micro = time.tv_usec / 1000;
	return (sec + micro);
}

long	get_relative_time(long long start)
{
	long long	time;

	time = get_time();
	return (time - start);
}

void	correct_usleep(long long time_to_sleep)
{
	long long	start_time;

	start_time = get_time();
	while (get_time() - start_time < time_to_sleep)
		usleep(500);
}
