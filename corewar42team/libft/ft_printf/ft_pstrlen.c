/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:37:49 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/10 18:54:53 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

size_t	ft_pstrlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}

int		ft_numlen(long long int num)
{
	int		i;

	i = 0;
	if (num && num < 0)
		num = -num;
	if (num == 0)
		return (1);
	if (num)
	{
		while (num > 0)
		{
			i++;
			num /= 10;
		}
	}
	return (i);
}
