/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:21:30 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/14 13:20:52 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ans;

	i = 0;
	ans = (char *)big;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while ((i + j) < len && big[i + j] && big[i + j] == little[j])
			{
				if (!(little[j + 1]))
					return (ans + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
/*int main()
{
   #include <stdio.h>

int main()
{
	const char str[] = "TPointoooooooutori";
    const char substr[] = "Point";

    printf("%s\n", ft_strnstr(str, substr, 10)); 
    printf("%s\n", ft_strnstr(str, substr, 3));  
    printf("%s\n", ft_strnstr(str, "", 3)); 
}*/
