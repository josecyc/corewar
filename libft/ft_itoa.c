/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:20:59 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/19 20:14:02 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_length(int n)
{
	int length;

	length = 1;
	if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n / 10 != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		length;

	length = ft_get_length(n);
	result = (char *)malloc(sizeof(char) * length + 1);
	if (!result)
		return (NULL);
	result[length--] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			result[length--] = 8 + '0';
			n = n / 10;
		}
		n = -n;
		result[0] = '-';
	}
	while (n / 10 != 0)
	{
		result[length--] = n % 10 + '0';
		n = n / 10;
	}
	result[length--] = n % 10 + '0';
	return (result);
}
