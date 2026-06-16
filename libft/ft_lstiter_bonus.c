/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:51:46 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/20 10:52:26 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void print(void *str)
{
	printf("%s\n",(char *) str);
}*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
/*int	main()
{
	t_list *a = ft_lstnew("Abdallah");
	t_list *b = ft_lstnew("42");
	t_list *c = ft_lstnew("Amman");
	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, c);
	ft_lstiter(a,print);
}*/
