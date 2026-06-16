/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:12:15 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/20 17:18:26 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;

	temp = (void *)malloc(nmemb * size);
	if (!temp)
		return (temp);
	ft_bzero(temp, size * nmemb);
	return ((void *)temp);
}
