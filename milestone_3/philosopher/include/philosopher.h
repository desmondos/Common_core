/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:12:15 by candriam          #+#    #+#             */
/*   Updated: 2024/12/26 07:59:43 by candriam         ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	int				num_forks;
	long			*meals_eaten;
	long long		*last_meal_time;
	long			start_time;
	long			num_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				num_must_eat;
	pthread_t		thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mutex;
}				t_philo;

int				main(int argc, char **argv);
void			ft_usleep(long long time_to_sleep);
void			*safe_malloc(size_t size);
long long		get_time(void);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			put_error(char *msg);
int				check_pos_nbr(char *str);
void			free_all(t_philo *philos, t_philo *state);
int				is_valid_args(int argc, char **argv, t_philo *philo);
long			ft_atol(const char *nptr);
t_philo			*init_simulation(int argc, char **argv);
t_philo			*init_philo(t_philo *philo);
pthread_mutex_t	*init_forks(int num_philos);
long long		*init_last_meal_time(int num_philo);
void			init_all_data(t_philo *philos, t_philo *philo,
					pthread_mutex_t *num_forks, long long *last_meal_time);
t_philo			*set_data_health(t_philo *philos);
void			philo_to_data(t_philo *philos, t_philo *data);
bool			check_meals_eaten(t_philo *data);
void			*check_philos_state(void *philos);
void			*philo_routine(void *philo);
void			create_threads(t_philo *philos);
void			sleeping(t_philo *philos);
void			thinking(t_philo *philos);
void			take_forks(t_philo *philos);
void			eating(t_philo *philos);
void			put_forks(t_philo *philos);
void			to_dead(int id, long time);
void			print_action(t_philo *philo, int id, char *action);

#endif
