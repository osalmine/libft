/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:57:27 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/24 13:27:48 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *start;
	t_list *elem;

	start = NULL;
	if (lst)
	{
		start = f(ft_lstnew(lst->content, lst->content_size));
		if (!start)	
			return (NULL);
		elem = start;
		while ((lst = lst->next))
		{
			elem->next = f(ft_lstnew(lst->content, lst->content_size));
			if (!elem->next)
				return (NULL);
			elem = elem->next;
		}
		return (start);
	}
	return (NULL);
}
