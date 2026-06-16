/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:41:38 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/20 11:45:25 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}
/*int main(void)
{
    t_list *head = ft_lstnew("0");
    t_list *node1 = ft_lstnew("1");
    t_list *node2 = ft_lstnew("2");

    ft_lstadd_front(&head, node1);
    ft_lstadd_front(&head, node2); 
    printf("%s\n", (char *)head->content);          
    printf("%s\n", (char *)head->next->content);
    printf("%s\n", (char *)head->next->next->content);
    return 0;
}*/
