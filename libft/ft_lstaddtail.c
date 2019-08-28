/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 09:27:19 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/20 10:15:16 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddtail(t_list **alst, t_list *new)
{
	t_list *cpy;

	if (*alst == NULL)
		*alst = new;
	else
	{
		cpy = *alst;
		if (new)
		{
			while ((*alst)->next)
				*alst = (*alst)->next;
			(*alst)->next = new;
		}
		*alst = cpy;
	}
}
