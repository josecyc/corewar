/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:37:56 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/19 20:11:12 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match(const char *haystack, const char *needle)
{
	int result;

	result = 1;
	while (*needle != '\0')
	{
		if (*needle != *haystack)
			return (0);
		needle++;
		haystack++;
	}
	return (1);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	if (ft_strcmp(needle, "") == 0)
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (match(haystack, needle) == 1)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
