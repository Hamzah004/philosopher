/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:48:43 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/18 15:42:49 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t;

	t = (unsigned char *)s;
	while (n--)
		*t++ = '\0';
}
// int main()
// {
// 	char *str = "Abdallah";
// 	ft_bzero(str, 7);
// 	printf("%zu",ft_strlen(str));
// }