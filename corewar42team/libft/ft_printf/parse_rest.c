/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:33:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/10 18:55:01 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	parse_width(char **fmt, t_elem *t_node)
{
	if (**fmt >= '0' && **fmt <= '9')
		t_node->width = ft_patoi(*fmt);
}

void	parse_precision(char **fmt, t_elem *t_node, va_list ap)
{
	va_list ap3;

	va_copy(ap3, ap);
	while (**fmt != '.' && !ft_pstrchr(CONV_TYPES, **fmt)
	&& !ft_pstrchr(MOD_TYPES, **fmt))
		*fmt = *fmt + 1;
	if (**fmt == '.')
	{
		*fmt = *fmt + 1;
		if ((ft_pstrchr(CONV_TYPES, **fmt) || **fmt == '0'))
			t_node->just_dec = 1;
		if (**fmt >= '0' && **fmt <= '9')
			t_node->prec = ft_patoi(*fmt);
		t_node->prec_bl = 1;
	}
	if (va_arg(ap3, long long int) == 0 && (t_node->just_dec == 1 ||
	t_node->hashsign == 1))
		t_node->val_zero = 1;
}

void	parse_modifier(char **fmt, t_elem *t_node)
{
	while (**fmt >= '0' && **fmt <= '9')
		*fmt = *fmt + 1;
	if (**fmt == 'h' && *(*fmt + 1) == 'h')
		t_node->mod = "hh";
	else if (**fmt == 'h' && *(*fmt + 1) != 'h')
		t_node->mod = "h";
	if (**fmt == 'l' && *(*fmt + 1) == 'l')
		t_node->mod = "ll";
	else if (**fmt == 'l' && *(*fmt + 1) != 'l')
		t_node->mod = "l";
	if (**fmt == 'L')
		t_node->mod = "L";
}

void	parse_conv_type(char **fmt, t_elem *t_node)
{
	while (**fmt == 'l' || **fmt == 'h' || **fmt == 'L' ||
	!ft_pstrchr(CONV_TYPES, **fmt))
		*fmt = *fmt + 1;
	if (**fmt == 'd')
		t_node->type = 'd';
	if (**fmt == 'u')
		t_node->type = 'u';
	if (**fmt == 'i')
		t_node->type = 'i';
	if (**fmt == 's')
		t_node->type = 's';
	if (**fmt == 'c')
		t_node->type = 'c';
	if (**fmt == 'o')
		t_node->type = 'o';
	if (**fmt == 'x')
		t_node->type = 'x';
	if (**fmt == 'X')
		t_node->type = 'X';
	if (**fmt == 'p')
		t_node->type = 'p';
	if (**fmt == 'f')
		t_node->type = 'f';
	if (**fmt == '%')
		t_node->type = '%';
}

void	parse_neg_num(va_list ap, t_elem *t_node)
{
	va_list			ap4;
	long long int	neg;

	va_copy(ap4, ap);
	neg = va_arg(ap4, int);
	if (neg < 0)
		t_node->neg_num = 1;
}
