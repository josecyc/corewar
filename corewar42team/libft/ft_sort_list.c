/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 10:26:23 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/20 12:46:10 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*sort_list(t_list *list, int (*f)(void *, void*))
{
	t_list	*cpy;
	void	*content;
	size_t	size;

	cpy = list;
	while (cpy && cpy->next)
	{
		if (f(cpy->content, cpy->next->content) > 0)
		{
			content = cpy->next->content;
			size = cpy->next->content_size;
			cpy->next->content = cpy->content;
			cpy->next->content_size = size;
			cpy->content = content;
			cpy->content_size = size;
			cpy = list;
		}
		else
			cpy = cpy->next;
	}
	return (list);
}
