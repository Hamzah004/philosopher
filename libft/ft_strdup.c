/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:36:10 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/13 17:59:53 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"  

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*copy;

	size = ft_strlen(s1);
	i = 0;
	copy = (char *)malloc((size + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (i < size)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
