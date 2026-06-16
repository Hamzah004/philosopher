/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 09:58:44 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/18 16:40:46 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void    to_up(unsigned int i, char *c)
{
	if (i %2 != 0)
		{
			if (*c >= 'a' && *c <= 'z')
				*c -= 32;
		}
	else
	{
		if (*c >= 'A' && *c <= 'Z')
			*c += 32;
	}
}*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}
/*int main()
{
	char str[] = "abdallah";
	ft_striteri(str, to_up);
	printf("%s\n", str);
}*/
