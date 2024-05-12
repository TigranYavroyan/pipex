/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:58:06 by tyavroya          #+#    #+#             */
/*   Updated: 2024/01/30 13:09:38 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_list;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	res_list = ft_lstnew(f(lst->content));
	if (!res_list)
		return (NULL);
	head = res_list;
	while (lst->next)
	{
		res_list->next = ft_lstnew((f(lst->next->content)));
		if (!res_list)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
		res_list = res_list->next;
	}
	return (head);
}
