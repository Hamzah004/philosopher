/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:40:47 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/20 10:41:11 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp -> next = new;
}
/*int main(void)
{
    t_list *head = ft_lstnew("0");
    t_list *node1 = ft_lstnew("1");
    t_list *node2 = ft_lstnew("2");

    ft_lstadd_back(&head, node1);
    ft_lstadd_back(&head, node2);
    printf("%s\n", (char *)head->content);
    printf("%s\n", (char *)head->next->content);
    printf("%s\n", (char *)head->next->next->content);
    return 0;
}*/
