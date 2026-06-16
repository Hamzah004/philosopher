/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:12:21 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/18 15:12:47 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	i = 0;
	temp = (char *)malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (s[start + i] && i < len)
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
/*int main()
{
	char *str ="0123456789";
	printf("%s\n",ft_substr(str,9 ,10));
	//printf("%s",ft_substr("tripouille", 1, 1));
}*/
