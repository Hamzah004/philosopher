/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:07:05 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/18 17:45:18 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	sizee;

	i = 0;
	sizee = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (sizee);
}
/*int	main()
{
	char src[]="abdallah 42";
	char dest[]="";
	size_t x = ft_strlcpy(dest,src,3);
	printf("%zu" , x);
}*/
