/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 19:52:29 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/19 21:40:03 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char c1;
	unsigned char c2;

	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	c1 = (unsigned char)*s1;
	c2 = (unsigned char)*s2;
	if (n == 0)
		return (1);
	while (c1 == c2 && n-- > 0)
	{
		if (c1 == '\0' || n == 1)
			return (1);
		s1++;
		s2++;
		c1 = (unsigned char)*s1;
		c2 = (unsigned char)*s2;
	}
	return (0);
}
