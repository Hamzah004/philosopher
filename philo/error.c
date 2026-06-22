/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:00:00 by hbani-at          #+#    #+#             */
/*   Updated: 2026/06/21 18:38:05 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(t_error error)
{
	if (error == ERROR_SUCCESS)
		return ;
	ft_putstr_fd("Error\n", 2);
	if (error == ERROR_INVALID_ARGS)
		ft_putstr_fd("Invalid number of arguments\n", 2);
	if (error == ERROR_INVALID_NUMBER)
		ft_putstr_fd("Invalid number\n", 2);
	if (error == ERROR_MEMORY)
		ft_putstr_fd("Invalid Memory allocation\n", 2);
	if (error == MUTEX_INIT_ERROR)
		ft_putstr_fd("Mutex Init Error\n", 2);
}
