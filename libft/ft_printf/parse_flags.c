/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:47:09 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/10 18:54:58 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	parse_flags(char **fmt, t_elem *t_node)
{
	int		i;

	i = 0;
	*fmt = *fmt + 1;
	while (ft_pstrchr(FLAGS, **fmt))
	{
		if (**fmt == '#')
			t_node->hashsign = 1;
		if (**fmt == '-')
			t_node->minus_sign = 1;
		if (**fmt == ' ')
			t_node->space = 1;
		if (**fmt == '+')
			t_node->plus_sign = 1;
		if (**fmt == '0')
			t_node->zero = 1;
		*fmt = *fmt + 1;
	}
}
