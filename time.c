/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:36:25 by hbani-at          #+#    #+#             */
/*   Updated: 2026/06/21 03:53:37 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

long long	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	timestamp(t_data *data)
{
	return (get_time_ms() - data->start_time);
}

void	better_usleep(long long time_to_eat)
{
	long long	start;

	start = get_time_ms();
	while (get_time_ms() < start + time_to_eat)
		;
}
