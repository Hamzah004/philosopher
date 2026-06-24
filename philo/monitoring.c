/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 03:10:19 by hbani-at          #+#    #+#             */
/*   Updated: 2026/06/21 03:53:41 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->print_mutex);
	printf("%lld %d died\n", get_time_ms() - data->start_time,
		data->philos[i].id);
	pthread_mutex_lock(&data->sim_mutex);
	data->sim_running = 0;
	pthread_mutex_unlock(&data->sim_mutex);
	pthread_mutex_unlock(&data->print_mutex);
}

static int	check_death(t_data *data, int *i)
{
	pthread_mutex_lock(&data->philos[*i].meal_mutex);
	if (get_time_ms() - data->philos[*i].last_meal > data->time_to_die)
	{
		print_death(data, *i);
		pthread_mutex_unlock(&data->philos[*i].meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->philos[*i].meal_mutex);
	return (0);
}

static void	check_logic(t_data *data, int *j)
{
	int	full;

	full = 1;
	while (*j < data->philo_count)
	{
		pthread_mutex_lock(&data->philos[*j].meal_mutex);
		if (data->philos[*j].meal_count < data->must_eat)
			full = 0;
		pthread_mutex_unlock(&data->philos[*j].meal_mutex);
		(*j)++;
	}
	if (full)
	{
		pthread_mutex_lock(&data->sim_mutex);
		data->sim_running = 0;
		pthread_mutex_unlock(&data->sim_mutex);
		return ;
	}
}

static int	check_all_full(t_data *data)
{
	int	j;

	if (data->must_eat <= 0)
		return (0);
	j = 0;
	check_logic(data, &j);
	pthread_mutex_lock(&data->sim_mutex);
	if (!data->sim_running)
	{
		pthread_mutex_unlock(&data->sim_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->sim_mutex);
	return (0);
}

void	monitoring(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->philo_count)
		{
			if (check_death(data, &i))
				return ;
			i++;
		}
		if (check_all_full(data))
			return ;
		usleep(1000);
	}
}
