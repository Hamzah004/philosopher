/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 21:06:30 by hbani-at          #+#    #+#             */
/*   Updated: 2026/06/21 18:38:59 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "pthread.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_error
{
	ERROR_SUCCESS = 0,
	ERROR_INVALID_ARGS = 1,
	ERROR_INVALID_NUMBER = 2,
	ERROR_MEMORY = 3,
	MUTEX_INIT_ERROR = 4,
	PTHREAD_CREATE_ERROR = 5
}					t_error;

typedef struct s_philo
{
	int				id;
	long			meal_count;
	long long		last_meal;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread_id;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				philo_count;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				must_eat;
	long long		start_time;
	int				sim_running;
	pthread_mutex_t	sim_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_data;

void				print_error(t_error error);
t_error				init_data(t_data *data, int argc, char **argv);
long long			get_time_ms(void);
long long			timestamp(t_data *data);
void				better_usleep(long long ms, t_data *data);
void				print_state(t_data *data, int id, char *message);
void				*routine(void *s);
void				cleanup(t_data *data);
void				monitoring(t_data *data);
int					sim_stop(t_data *data);
long long			ft_atol(const char *nptr);
int					ft_atoi(const char *nptr);
int					ft_isdigit(int c);
void				ft_putstr_fd(char *s, int fd);

#endif
