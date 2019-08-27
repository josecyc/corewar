/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 20:33:07 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/10 18:55:03 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int		ft_pstrcmp(const char *s1, const char *s2)
{
	unsigned char c1;
	unsigned char c2;

	c1 = (unsigned char)*s1;
	c2 = (unsigned char)*s2;
	while (c1 == c2)
	{
		if (c1 == '\0')
			return (c1 - c2);
		s1++;
		s2++;
		c1 = (unsigned char)*s1;
		c2 = (unsigned char)*s2;
	}
	return (c1 - c2);
}
