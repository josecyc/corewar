/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 22:07:17 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/01 22:24:57 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *lst;

	lst = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			lst = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (lst);
}