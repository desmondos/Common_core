/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/27 08:47:55 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <bits/types/struct_timeval.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>
# include <stddef.h>
# include <limits.h>
# include <errno.h>

typedef enum e_mutex
{
	PRINT,
	MEAL,
	DONE,
	DIED,
	TOTAL
}			t_mutex;

typedef struct s_data
{
	int				is_done;
	int				has_died;
	long			philo_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_think;
	long			meals_required;
	long			sim_start;
	pthread_mutex_t	*mutex;
}				t_data;

typedef struct s_philo
{
	int				id;
	long			last_meal_time;
	long			meal_count;
	long			left_fork;
	long			right_fork;
	pthread_mutex_t	*fork;
	t_data			*data;
}				t_philo;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	*safe_malloc(size_t size);
void	free_all(t_philo *philo, t_data *data);
int		check_valid_args(int argc, char **argv);
int		init_philo(t_philo **philo, t_data *data);
int		init_data_mutexes(t_data **data);
int		init_data(t_data **data, int argc, char **argv);
int		init_all(t_philo **philo, t_data **data, int argc, char **argv);
int		main(int argc, char **argv);
int		start_eating(t_philo *self);
int		finish_eating(t_philo *self);
int		eating(t_philo *self);
void	*simulation(void *arg);
void	print_action(t_philo *philo, char *action);
void	died(t_data *data);
void	done(t_data *data);
int		check_died(t_philo *philo);
int		check_done(t_philo *philo);
void	destroy_mutexes(t_philo *philo, t_data *data);
int		all_done(t_philo *philo, t_data *data);
int		monitor(t_philo *philo, t_data *data);
int		simulator(t_philo *philo, t_data *data);
long	get_time(void);
long	get_relative_time(long long start);
void	correct_usleep(long long time_to_sleep);
int		is_digit(char *str);
int		check_args(int argc, char **argv);
long	ft_atol(char const *str);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

#endif
