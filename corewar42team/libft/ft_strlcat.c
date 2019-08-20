/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:04:35 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/02 20:41:26 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src,
		size_t dstsize)
{
	size_t lens;

	lens = ft_strlen(src) + dstsize;
	if (ft_strlen(dst) < dstsize)
		lens = ft_strlen(src) + ft_strlen(dst);
	if (dstsize < ft_strlen(dst) + 1)
		dstsize = 0;
	else
		dstsize -= ft_strlen(dst) + 1;
	while (*dst != '\0')
		dst++;
	while (*src != '\0' && dstsize != 0)
	{
		*dst = *src;
		src++;
		dst++;
		dstsize--;
	}
	*dst = '\0';
	return (lens);
}
