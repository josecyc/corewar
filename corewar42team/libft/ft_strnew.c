/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 19:06:08 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/01 19:18:42 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void	*new;
	char	*result;

	new = ft_memalloc(size + 1);
	if (new == NULL)
		return (NULL);
	result = new;
	ft_bzero(result, size + 1);
	return (result);
}
