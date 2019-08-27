/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:08:10 by jdiaz             #+#    #+#             */
/*   Updated: 2019/01/26 19:08:20 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

void	byte_print(int nb, int bytes, int fd)
{
	int		tmp;

	while (--bytes >= 0)
	{
		tmp = nb;
		tmp = tmp >> (8 * bytes);
		tmp = tmp & 255;
		ft_putchar_fd((char)tmp, fd);
	}
}

int		all_whitespace(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t')
			return (0);
		line++;
	}
	return (1);
}

int		power_of2(int exp)
{
	int result;

	result = 1;
	while (exp > 0)
	{
		result *= 2;
		exp--;
	}
	return (result);
}
