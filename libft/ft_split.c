/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:24:40 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/20 11:41:16 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c, size_t *i, size_t *j)
{
	size_t	k;
	size_t	count;

	k = 0;
	*i = 0;
	*j = 0;
	count = 0;
	while (s[k])
	{
		while (s[k] == c)
			k++;
		if (s[k])
			count++;
		while (s[k] && (s[k] != c))
			k++;
	}
	return (count);
}

static char	*ft_make_w(char const *s, size_t l, size_t r)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc((r - l + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (l < r)
	{
		word[i] = s[l];
		l++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**clear(char **temp, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i && temp[j])
	{
		free (temp[j]);
		j++;
	}
	free (temp);
	return (0);
}

static char	**putnull(char **str, size_t i)
{
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		le;
	char	**temp;

	if (!s)
		return (NULL);
	temp = malloc((ft_count(s, c, &i, &j) + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	le = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && le < 0)
			le = i;
		else if ((s[i] == c || i == ft_strlen(s)) && (le >= 0))
		{
			temp[j++] = ft_make_w(s, le, i);
			if (!(temp[j - 1]))
				return (clear(temp, i));
			le = -1;
		}
		i++;
	}
	return (putnull(temp, j));
}
/*int main()
{
	char *str = ",,abdallah,,42,,Amman,any,";
	char **new_str = ft_split(str, ',');
	for (int i = 0; new_str[i]; i++)
		printf("%s\n", new_str[i]);
}*/
