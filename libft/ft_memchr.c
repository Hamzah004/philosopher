/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:24:25 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/16 18:50:36 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	int				i;

	t = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (t[i] == (unsigned char)c)
		{
			return ((unsigned char *)t + i);
		}
		i++;
	}
	return (NULL);
}
/*int main()
{
	char *str = "Abdallah";
	str = ft_memchr(str, 108, 8);
	printf("%s", str);
}*/
