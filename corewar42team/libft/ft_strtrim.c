/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:23:30 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/19 20:54:48 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	l;
	char	*new;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	while (l > 0 && (s[l - 1] == ' ' ||
				s[l - 1] == '\t' || s[l - 1] == '\n'))
		l--;
	while (*s == ' ' || *s == '\t' || *s == '\n')
	{
		if (l != 0)
			l--;
		s++;
	}
	new = ft_strnew(l + 1);
	if (!new)
		return (NULL);
	ft_strncpy(new, s, l);
	new[l] = '\0';
	return (new);
}
