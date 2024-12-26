/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/22 17:39:18 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

long	get_abs_time(void)
{
	struct timeval	time;
	unsigned long	sec;
	unsigned long	micro;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "Error: GETTIMEOFDAY(2)\n", 28);
	sec = time.tv_sec * 1000;
	micro = time.tv_usec / 1000;
	return (sec + micro);
}

long	get_rel_time(unsigned long start)
{
	unsigned long	abs_time;

	abs_time = get_abs_time();
	return (abs_time - start);
}

void	correct_usleep(unsigned long msec)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		usleep(msec * 50);
		i++;
	}
}
