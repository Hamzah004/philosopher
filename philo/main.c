/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 19:58:47 by hbani-at          #+#    #+#             */
/*   Updated: 2026/06/21 18:37:42 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+')
		i++;
	if (!s[i])
		return (1);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

t_error	input_validation(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (ERROR_INVALID_ARGS);
	i = 0;
	while (++i < argc)
	{
		if (is_valid_number(argv[i]))
			return (ERROR_INVALID_NUMBER);
	}
	return (ERROR_SUCCESS);
}

static t_error	start_sim(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, routine,
				&data->philos[i]))
		{
			data->threads_created = i;
			pthread_mutex_lock(&data->sim_mutex);
			data->sim_running = 0;
			pthread_mutex_unlock(&data->sim_mutex);
			cleanup(data);
			return (PTHREAD_CREATE_ERROR);
		}
		i++;
	}
	data->threads_created = i;
	monitoring(data);
	cleanup(data);
	return (ERROR_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_error	err;

	err = input_validation(argc, argv);
	if (err != ERROR_SUCCESS)
	{
		print_error(err);
		return (err);
	}
	err = init_data(&data, argc, argv);
	if (err != ERROR_SUCCESS)
	{
		print_error(err);
		return (err);
	}
	start_sim(&data);
	return (err);
}
