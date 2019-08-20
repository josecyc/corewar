/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 10:10:16 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/20 12:46:42 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	get_hexa(unsigned int num)
{
	if (num < 10)
		return (num + '0');
	else if (num == 10)
		return ('a');
	else if (num == 11)
		return ('b');
	else if (num == 12)
		return ('c');
	else if (num == 13)
		return ('d');
	else if (num == 14)
		return ('e');
	else
		return ('f');
}

static int	ft_uilength(unsigned int n, unsigned int base)
{
	int length;

	length = 1;
	while (n / base != 0)
	{
		n = n / base;
		length++;
	}
	return (length);
}

char		*nbase_uitoa(unsigned int num, unsigned int base)
{
	char	*result;
	int		length;

	length = ft_uilength(num, base);
	result = (char *)malloc(sizeof(char) * length + 1);
	if (!result)
		return (NULL);
	result[length--] = '\0';
	while (num / base != 0)
	{
		result[length--] = get_hexa(num % base);
		num = num / base;
	}
	result[0] = get_hexa(num % base);
	return (result);
}
