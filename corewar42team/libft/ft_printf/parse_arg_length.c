/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 17:47:48 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/10 18:54:43 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	parse_arg(va_list ap2, t_elem *t_node)
{
	if ((t_node->type == 'd' || t_node->type == 'i' || t_node->type == 'f') &&
		(ft_pstrcmp(t_node->mod, "") == 0 || ft_pstrcmp(t_node->mod, "h") ||
		ft_pstrcmp(t_node->mod, "hh")))
		t_node->arg_length = ft_numlen(va_arg(ap2, int));
	if (t_node->type == 'x' || t_node->type == 'X' || t_node->type == 'o' ||
	t_node->type == 'u')
	{
		itoa_blen(va_arg(ap2, unsigned long long), t_node);
		t_node->arg_length = t_node->blen;
	}
	if (t_node->type == 'f')
	{
		if (t_node->prec == 0)
			t_node->arg_length += 9;
		t_node->arg_length = ft_numlen(va_arg(ap2, double)) + 1;
	}
	if ((t_node->type == 'c' && va_arg(ap2, int) != 0) || t_node->type == '%')
		t_node->arg_length = 1;
}

void	parse_arg_length(va_list ap, t_elem *t_node)
{
	va_list	ap2;
	int		slen;

	va_copy(ap2, ap);
	if (t_node->type == 's')
	{
		slen = ft_pstrlen(va_arg(ap2, char *));
		if (t_node->prec_bl == 1 && t_node->minus_sign == 0 &&
		slen > t_node->prec)
			t_node->arg_length = t_node->prec;
		else
		{
			t_node->arg_length = slen;
			if (t_node->arg_length == 0)
				t_node->empty = 1;
		}
	}
	if ((t_node->type == 'd' || t_node->type == 'i' || t_node->type == 'f') &&
	ft_pstrcmp(t_node->mod, "ll") == 0)
		t_node->arg_length = ft_numlen(va_arg(ap2, long long int));
	if ((t_node->type == 'd' || t_node->type == 'i' || t_node->type == 'f') &&
	ft_pstrcmp(t_node->mod, "l") == 0)
		t_node->arg_length = ft_numlen(va_arg(ap2, long int));
	parse_arg(ap2, t_node);
}
