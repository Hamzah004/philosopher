/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 19:58:47 by hbani-at          #+#    #+#             */
/*   Updated: 2026/06/20 00:38:58 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "philo.h"

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (1);
	while (s[i] != '\0')
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
		if (!is_valid_number(argv[i]))
			return (ERROR_INVALID_NUMBER);
	}
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
	return (err);
}
