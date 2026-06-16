/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:45:15 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/23 12:14:39 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void print(void *str)
{
	printf("%s\n",(char *) str);
}*/
/*void *do_something(void *data)
{
    char *str = (char *)data;
    char *new_str = malloc(ft_strlen(str) + 1);
    if (!new_str)
        return (NULL);
    ft_strlcpy(new_str, str,ft_strlen(str));
    new_str[0] = new_str[0] - 32;
    return (new_str);
}*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	temp = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst -> content));
		if (!node)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		ft_lstadd_back(&temp, node);
		lst = lst ->next;
	}
	return (temp);
}
/*int	main()
{
	t_list *a = ft_lstnew("abdallah");
	t_list *b = ft_lstnew("42");
	t_list *c = ft_lstnew("amman");
	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, c);
	t_list *new_lst = ft_lstmap(a, do_something, free);
	ft_lstiter(new_lst,print);
}*/
