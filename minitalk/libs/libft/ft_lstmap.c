/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:20:31 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/09 15:14:00 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list;
	void	*r_func;

	if (!lst)
		return (NULL);
	list = NULL;
	while (lst)
	{
		r_func = f(lst->content);
		new = ft_lstnew(r_func);
		if (new == NULL)
		{
			del(r_func);
			ft_lstclear(&list, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&list, new);
	}
	return (list);
}
