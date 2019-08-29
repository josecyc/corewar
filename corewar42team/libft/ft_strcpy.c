/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:56:25 by jdiaz             #+#    #+#             */
/*   Updated: 2018/09/12 08:55:14 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *source)
{
	char *dst;

	dst = dest;
	while (*source != '\0')
	{
		*dst = *source;
		dst++;
		source++;
	}
	*dst = *source;
	return (dest);
}
