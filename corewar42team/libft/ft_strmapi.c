/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 19:37:44 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/19 21:03:49 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	size_t			length;
	char			*result;

	index = 0;
	if (!s)
		return (NULL);
	length = ft_strlen(s);
	result = ft_strnew(length);
	if (!result)
		return (NULL);
	while (s[index] != '\0')
	{
		result[index] = f(index, s[index]);
		index++;
	}
	return (result);
}
