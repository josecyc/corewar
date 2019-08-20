/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:46:38 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/02 19:49:34 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*cpy;

	cpy = (char *)s1;
	while (*cpy != '\0')
		cpy++;
	while (n > 0 && *s2 != '\0')
	{
		*cpy = *s2;
		cpy++;
		s2++;
		n--;
	}
	*cpy = '\0';
	return ((char *)s1);
}
