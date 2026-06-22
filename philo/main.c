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

static int	is_valid_number(char *s, int max_digits)
{
	int	i;
	int	digit_len;

	i = 0;
	if (s[i] == '+')
		i++;
	if (!s[i])
		return (1);
	digit_len = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
		digit_len++;
	}
	if (digit_len > max_digits)
		return (1);
	return (0);
}

t_error	input_validation(int argc, char **argv)
{
	int	i;
	int	max_digits;

	if (argc < 5 || argc > 6)
		return (ERROR_INVALID_ARGS);
	i = 0;
	while (++i < argc)
	{
		if (i == 2 || i == 3 || i == 4)
			max_digits = 19;
		else
			max_digits = 10;
		if (is_valid_number(argv[i], max_digits))
			return (ERROR_INVALID_NUMBER);
	}
	return (ERROR_SUCCESS);
}

static void	start_sim(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_create(&data->philos[i].thread_id, NULL, routine,
			&data->philos[i]);
		i++;
	}
	monitoring(data);
	cleanup(data);
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
