/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:00:57 by jdiaz             #+#    #+#             */
/*   Updated: 2018/09/12 16:27:39 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char a;
	unsigned char *copy;

	copy = (unsigned char *)b;
	a = (unsigned char)c;
	while (len)
	{
		*copy = a;
		copy++;
		len--;
	}
	return (b);
}
