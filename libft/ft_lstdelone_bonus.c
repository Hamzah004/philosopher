/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:52:43 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/20 10:53:10 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}
/*int main()
{
    t_list *head = ft_lstnew(strdup("0"));
    t_list *node1 = ft_lstnew(strdup("1"));
    t_list *node2 = ft_lstnew(strdup("2"));

    ft_lstadd_front(&head, node1);
    ft_lstadd_front(&head, node2);

    printf("%d\n", ft_lstsize(head));

    t_list *tmp = head;
    head = head->next;
    ft_lstdelone(tmp, free);         

    printf("%d\n", ft_lstsize(head));
}*/
