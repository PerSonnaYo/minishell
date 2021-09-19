/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:05:32 by mdude             #+#    #+#             */
/*   Updated: 2020/11/06 11:05:36 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newelem;

	if (!lst || !f)
		return (NULL);
	newelem = ft_lstnew(f(lst->content));
	if (!newelem)
		return (NULL);
	lst = lst->next;
	newlist = newelem;
	while (lst)
	{
		newelem = newelem->next;
		newelem = ft_lstnew(f(lst->content));
		if (!newelem)
			ft_lstclear(&newelem, del);
		ft_lstadd_back(&newlist, newelem);
		lst = lst->next;
	}
	return (newlist);
}
