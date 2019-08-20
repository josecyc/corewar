/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:49:23 by jdiaz             #+#    #+#             */
/*   Updated: 2018/09/12 19:13:49 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	char	*copy;
	char	a;

	a = (char)c;
	copy = (char *)s1;
	while (*copy != '\0')
	{
		if (*copy == a)
			return (copy);
		copy++;
	}
	if (c == '\0')
		return (copy);
	return (NULL);
}
