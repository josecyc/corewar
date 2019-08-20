/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:42:47 by jdiaz             #+#    #+#             */
/*   Updated: 2018/09/12 19:22:44 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		index;
	int		length;
	char	*result;

	index = 0;
	length = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * length + 1);
	if (result == NULL)
		return (NULL);
	while (index < length)
	{
		result[index] = s1[index];
		index++;
	}
	result[index] = s1[index];
	return (result);
}
