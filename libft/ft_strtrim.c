/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:50:39 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/18 16:27:29 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_it(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	count(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	size_s1;

	i = 0;
	j = ft_strlen(s1);
	size_s1 = ft_strlen(s1);
	while (s1[i] && is_it(s1[i], set))
		i++;
	if (i == size_s1)
		return (0);
	while (j > i && is_it(s1[j - 1], set))
		j--;
	return ((j - i));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = count(s1, set);
	j = ft_strlen(s1);
	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (s1[i] && is_it(s1[i], set))
		i++;
	while (j > i && is_it(s1[j - 1], set))
		j--;
	ft_memcpy(temp, s1 + i, len);
	temp[len] = '\0';
	return (temp);
}

/*int main()
{
    char *s1  = "cbcHELLOabc";
    char  *set = "abc";
    printf("%s",ft_strtrim(s1, set));
}*/
