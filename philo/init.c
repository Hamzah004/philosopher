/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 00:52:42 by hbani-at          #+#    #+#             */
/*   Updated: 2026/06/21 18:38:11 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	parse_args(t_data *data, int argc, char **argv)
{
	data->philo_count = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atol(argv[5]);
	else
		data->must_eat = -1;
	data->start_time = get_time_ms();
	data->sim_running = 1;
}

static t_error	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (MUTEX_INIT_ERROR);
		data->forks_inited++;
		i++;
	}
	return (ERROR_SUCCESS);
}

static t_error	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meal_count = 0;
		data->philos[i].last_meal = data->start_time;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->philo_count];
		data->philos[i].data = data;
		if (pthread_mutex_init(&data->philos[i].meal_mutex, NULL))
			return (MUTEX_INIT_ERROR);
		data->philos_inited++;
		i++;
	}
	return (ERROR_SUCCESS);
}

static t_error	allocate_resources(t_data *data)
{
	if (pthread_mutex_init(&data->print_mutex, NULL)
		|| pthread_mutex_init(&data->sim_mutex, NULL))
		return (MUTEX_INIT_ERROR);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
	{
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->sim_mutex);
		return (ERROR_MEMORY);
	}
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
	{
		free(data->forks);
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->sim_mutex);
		return (ERROR_MEMORY);
	}
	return (ERROR_SUCCESS);
}

t_error	init_data(t_data *data, int argc, char **argv)
{
	t_error	err;

	parse_args(data, argc, argv);
	if (data->philo_count <= 0 || data->philo_count > INT_MAX
		|| data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
		return (ERROR_INVALID_NUMBER);
	if (argc == 6 && (data->must_eat <= 0 || data->must_eat > INT_MAX))
		return (ERROR_INVALID_NUMBER);
	data->forks_inited = 0;
	data->philos_inited = 0;
	data->threads_created = 0;
	err = allocate_resources(data);
	if (err != ERROR_SUCCESS)
		return (err);
	if (init_forks(data) != ERROR_SUCCESS || init_philos(data) != ERROR_SUCCESS)
	{
		cleanup(data);
		return (MUTEX_INIT_ERROR);
	}
	return (ERROR_SUCCESS);
}
