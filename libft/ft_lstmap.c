/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:05:13 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/19 21:12:42 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *cpy;

	if (!lst)
		return (NULL);
	begin = f(lst);
	cpy = begin;
	while (lst->next)
	{
		cpy->next = f(lst->next);
		lst = lst->next;
		cpy = cpy->next;
	}
	return (begin);
}
