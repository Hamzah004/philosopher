/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 21:06:30 by hbani-at          #+#    #+#             */
/*   Updated: 2026/06/18 03:03:39 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include "pthread.h"
# include <bits/pthreadtypes.h>

typedef enum e_error
{
	ERROR_SUCCESS = 0,
	ERROR_INVALID_ARGS = 1,
	ERROR_INVALID_NUMBER = 2,
	ERROR_MEMORY = 3
}					t_error;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
}					t_fork;

typedef struct s_philo
{
	int				id;
	long			meal_count;
	long long		last_meal;
	pthread_mutex_t	meal_mutex;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread_id;
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
	t_fork			*forks;
	t_philo			*philos;
}					t_data;

void				print_error(t_error error);

#endif
