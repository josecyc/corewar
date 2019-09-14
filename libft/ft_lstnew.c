/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:32:19 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/19 19:44:59 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*result;
	void	*cpy;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->next = NULL;
	result->content_size = content_size;
	cpy = (void *)malloc(content_size);
	if (!cpy)
		cpy = NULL;
	if (content == NULL)
	{
		cpy = NULL;
		result->content_size = 0;
	}
	else
		cpy = ft_memcpy(cpy, content, content_size);
	result->content = cpy;
	return (result);
}
