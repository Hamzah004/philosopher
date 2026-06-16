/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:41:28 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/18 15:36:10 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		p;

	i = 0;
	p = -1;
	while (s[i])
	{
		if (s[i] == (char) c)
			p = i;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	if (p != -1)
		return ((char *)(s + p));
	return (NULL);
}
/*int main()
{
	char *str = "abdallah";
	printf("%s\n",ft_strrchr(str,108));
	printf("%s", strrchr(str,108));
}*/
