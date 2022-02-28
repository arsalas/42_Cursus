/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:08:07 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/24 12:36:29 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*list;

	if (lst)
	{
		list = *lst;
		while (list)
		{
			aux = list->next;
			ft_lstdelone(list, del);
			list = aux;
		}
	}
	*lst = NULL;
}
