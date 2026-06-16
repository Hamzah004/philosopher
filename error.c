/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:00:00 by hbani-at          #+#    #+#             */
/*   Updated: 2025/12/29 20:06:48 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "philo.h"

void	print_error(t_error error)
{
	if (error == ERROR_SUCCESS)
		return ;
	ft_putstr_fd("Error\n", 2);
	if (error == ERROR_INVALID_ARGS)
		ft_putstr_fd("Invalid number of arguments\n", 2);
	else if (error == ERROR_FILE_NOT_FOUND)
		ft_putstr_fd("Map file not found\n", 2);
	else if (error == ERROR_FILE_EMPTY)
		ft_putstr_fd("Map file is empty\n", 2);
	else if (error == ERROR_INVALID_EXTENSION)
		ft_putstr_fd("Invalid file extension. Must be .ber\n", 2);
	else if (error == ERROR_MEMORY)
		ft_putstr_fd("Memory allocation failed\n", 2);
	else if (error == ERROR_INVALID_MAP)
		ft_putstr_fd("Invalid map character or missing required elements\n", 2);
	else if (error == ERROR_MAP_NOT_RECTANGULAR)
		ft_putstr_fd("Map is not rectangular\n", 2);
	else if (error == ERROR_MAP_NOT_SURROUNDED)
		ft_putstr_fd("Map is not surrounded by walls\n", 2);
	else if (error == ERROR_INVALID_PATH)
		ft_putstr_fd("The player can't access collectables or the exit\n", 2);
}
