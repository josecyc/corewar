/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigitstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:25:28 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/02/02 16:07:43 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigitstr(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		if (str[i] && str[i] == '-') // added
			i++;
		while (str[i])
		{
			if (ft_isdigit(str[i]) != 1)
				return (-1);
			i++;
		}
		return (1);
	}
	return (-1);
}
