/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:36:25 by hbani-at          #+#    #+#             */
/*   Updated: 2026/06/21 18:37:34 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	better_usleep(long long ms, t_data *data)
{
	long long	start;

	start = get_time_ms();
	while (get_time_ms() < start + ms)
	{
		if (sim_stop(data))
			break ;
		usleep(500);
	}
}
