/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:05:32 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/02 20:40:51 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		i;
	int		neg;

	i = 0;
	neg = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		neg = -1;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10;
		result += *str - '0';
		str++;
	}
	result = neg == -1 ? result * neg : result;
	return (result);
}
