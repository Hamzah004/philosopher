/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:24:03 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/18 16:34:35 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	u;
	size_t	len;

	i = 0;
	while (dst[i] && i < size)
	{
		i++;
	}
	len = i;
	u = 0;
	while (i + 1 < size && src[u])
	{
		dst[i] = src[u];
		i++;
		u++;
	}
	while (src[u])
	{
		u++;
	}
	if (len < size)
		dst[i] = '\0';
	return (len + u);
}

/*#include <bsd/string.h>
int main()
{
    char src[] = "abdallah 42";
    char dest[20] = "000";
    //size_t x = ft_strlcat(dest, src, 3);
	printf("%zu",ft_strlcat("12345","123",4));
    //printf("%zu\n", x);
}*/
