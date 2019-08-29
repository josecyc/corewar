/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:22:38 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/02 20:36:25 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*cpy;
	size_t			i;

	cpy = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*cpy = *(unsigned char *)src;
		cpy++;
		src++;
		i++;
	}
	return (dst);
}
