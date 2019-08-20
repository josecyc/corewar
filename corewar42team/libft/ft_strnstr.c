/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:45:57 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/19 20:13:34 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nmatch(const char *haystack, const char *needle, size_t len)
{
	int result;

	result = 1;
	while (*needle != '\0' && len > 0)
	{
		if (*needle != *haystack)
			return (0);
		needle++;
		haystack++;
		len--;
	}
	if (*needle != '\0')
		return (0);
	return (1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (ft_strcmp(needle, "") == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		if (nmatch(haystack, needle, len) == 1)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
