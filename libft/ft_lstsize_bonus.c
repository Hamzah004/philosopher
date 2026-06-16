/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:46:27 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/20 10:46:38 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}
/*int main()
{
    t_list *head;
    t_list *node1;
    t_list *node2;
    t_list *node3;

    head =  ft_lstnew("0");
    node1 = ft_lstnew("1");
    node2 = ft_lstnew("2");
    node3 = ft_lstnew("3");

    ft_lstadd_front(&head, node1);
    ft_lstadd_front(&head, node2);
    ft_lstadd_front(&head, node3);

    printf("%d\n", ft_lstsize(head));
    return 0;
}*/
