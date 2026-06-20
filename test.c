/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:37:26 by hbani-at          #+#    #+#             */
/*   Updated: 2026/06/19 22:04:08 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int	main(void)
{
	double	time_taken;

	struct timeval start, end;
	printf("%d\n", gettimeofday(&start, NULL));
	sleep(2);
	printf("%d\n", gettimeofday(&end, NULL));
	time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
	printf("time taken in seconds: %f\n", time_taken);
}
