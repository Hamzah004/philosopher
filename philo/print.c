/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 01:29:37 by hbani-at          #+#    #+#             */
/*   Updated: 2026/06/20 01:33:26 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_data *data, int id, char *message)
{
	pthread_mutex_lock(&data->print_mutex);
	pthread_mutex_lock(&data->sim_mutex);
	if (data->sim_running)
		printf("%lld %d %s\n", get_time_ms() - data->start_time, id, message);
	pthread_mutex_unlock(&data->sim_mutex);
	pthread_mutex_unlock(&data->print_mutex);
}
