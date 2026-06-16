/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:24:28 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/20 11:09:27 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	if (!lst)
		return (NULL);
	i = ft_lstsize(lst) - 1;
	while (i--)
		lst = lst ->next;
	return (lst);
}
/*int main()
{
    t_list *head = ft_lstnew("0");
    t_list *n1 = ft_lstnew("1");
    t_list *n2 = ft_lstnew("2");
    t_list *n3 = ft_lstnew("3");

    ft_lstadd_front(&head, n1);
    ft_lstadd_front(&head, n2);
    ft_lstadd_front(&head, n3);

    t_list *last = ft_lstlast(head);
    printf("%s\n", (char *)last->content);
}*/
