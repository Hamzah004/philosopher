/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:58:20 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/20 11:22:51 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char addOne(unsigned int i, char c) {return (i + c);}
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*temp;

	if (!s || !f)
		return (NULL);
	i = 0;
	temp = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (s[i])
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
/*int main()
{
	char *str = "1234";
	char *new = ft_strmapi(str, addOne);

	printf("%s\n", str);
	printf("%s\n", new);
}*/
