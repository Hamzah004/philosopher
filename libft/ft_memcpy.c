/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:41:42 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/19 10:31:52 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dstt;
	unsigned char	*srcc;

	if (!dst && !src)
		return (NULL);
	dstt = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dstt[i] = srcc[i];
		i++;
	}
	return (dst);
}
/*int main()
{
    //char str1[] = "Abdallah ";
    //char str2[10] = "1";
    //char str3[] = "Abdallah ";
    //char str4[10] = "1";
    ft_memcpy("", "", 4);
    //memcpy("", str3, sizeof(str3));

    //printf("%s\n",str2);
    //printf("%s",str3);

    return 0;
}*/
