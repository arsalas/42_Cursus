/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:14:49 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/20 18:19:44 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int		len;
	int		i;
	t_list	*aux;

	if (lst)
	{
		len = ft_lstsize(lst);
		aux = lst;
		i = 0;
		while (i < len)
		{
			f(aux->content);
			aux = aux->next;
			i++;
		}
	}
}
