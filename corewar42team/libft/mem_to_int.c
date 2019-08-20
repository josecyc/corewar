/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:45:35 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/31 08:20:19 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mem_to_int(int	*dst, int address, char *program, int bytes)
{
	while (bytes-- > 0)
	{
		*dst <<= 8;
		*dst = (*dst | ((int)program[address++] & 255));
	}
}
