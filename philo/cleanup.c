/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 03:10:19 by hbani-at          #+#    #+#             */
/*   Updated: 2026/06/21 04:00:00 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->threads_created)
		pthread_join(data->philos[i++].thread_id, NULL);
	i = 0;
	while (i < data->forks_inited)
		pthread_mutex_destroy(&data->forks[i++]);
	i = 0;
	while (i < data->philos_inited)
		pthread_mutex_destroy(&data->philos[i++].meal_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->sim_mutex);
	free(data->forks);
	free(data->philos);
}
