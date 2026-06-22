/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 01:37:23 by hbani-at          #+#    #+#             */
/*   Updated: 2026/06/21 17:53:28 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	sim_stop(t_data *data)
{
	int	stopped;

	pthread_mutex_lock(&data->sim_mutex);
	stopped = !data->sim_running;
	pthread_mutex_unlock(&data->sim_mutex);
	return (stopped);
}

static void	philo_take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_fork->fork);
		print_state(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(&philo->left_fork->fork);
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		print_state(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(&philo->right_fork->fork);
	}
	print_state(philo->data, philo->id, "has taken a fork");
}

static void	eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time_ms();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_state(data, philo->id, "is eating");
	better_usleep(data->time_to_eat, data);
}

void	handle_single_philo(t_philo *philo)
{
	if (philo->data->philo_count == 1)
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		print_state(philo->data, philo->id, "has taken a fork");
		while (!sim_stop(philo->data))
			;
		pthread_mutex_unlock(&philo->left_fork->fork);
		return ;
	}
	if (philo->id % 2 == 0)
		better_usleep(1, philo->data);
}

void	*routine(void *s)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)s;
	data = philo->data;
	handle_single_philo(philo);
	while (!sim_stop(data))
	{
		print_state(data, philo->id, "is thinking");
		philo_take_forks(philo);
		eating(philo);
		pthread_mutex_unlock(&philo->right_fork->fork);
		pthread_mutex_unlock(&philo->left_fork->fork);
		print_state(data, philo->id, "is sleeping");
		better_usleep(data->time_to_sleep, data);
		usleep(500);
	}
	return (NULL);
}
