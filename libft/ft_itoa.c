/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:48:09 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/16 19:16:21 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_int(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*num;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	len = size_int(n);
	num = (char *)malloc((len + 1));
	if (!num)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		num[0] = '-';
	}
	while (n > 0)
	{
		num[(len - 1) - i++] = (n % 10) + '0';
		n /= 10;
	}
	num[len] = '\0';
	return (num);
}
/*int main()
{
	printf("%s", ft_itoa(-632));
}*/
