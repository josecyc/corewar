/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:43:34 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/09 21:39:47 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	print_it(char *fmt, t_elem *t_node, va_list ap, int *count)
{
	(void)fmt;
	print_width(t_node, count);
	print_numsub_plus(t_node, count);
	print_space(t_node, count);
	print_precision(t_node, count);
	print_zeroes(t_node, count);
	print_conversion(t_node, count, ap);
	print_blanks_just_left(t_node, count);
}

void	ft_assign_node(t_elem *t_node)
{
	t_node->hashsign = 0;
	t_node->plus_sign = 0;
	t_node->space = 0;
	t_node->minus_sign = 0;
	t_node->zero = 0;
	t_node->width = 0;
	t_node->width_blanks = 0;
	t_node->left_blanks = 0;
	t_node->zeroes = 0;
	t_node->prec = 0;
	t_node->prec_bl = 0;
	t_node->unsig_type = 0;
	t_node->sig_type = 0;
	t_node->base = 0;
	t_node->neg_num = 0;
	t_node->counter = 0;
	t_node->just_dec = 0;
	t_node->blen = 0;
	t_node->arg_length = 0;
	t_node->val_zero = 0;
	t_node->empty = 0;
	t_node->mod = "";
}

void	ft_cases(char *fmt, va_list ap, int *count)
{
	t_elem t_node;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			ft_assign_node(&t_node);
			parse_flags(&fmt, &t_node);
			parse_neg_num(ap, &t_node);
			parse_width(&fmt, &t_node);
			parse_precision(&fmt, &t_node, ap);
			parse_modifier(&fmt, &t_node);
			parse_conv_type(&fmt, &t_node);
			parse_arg_length(ap, &t_node);
			parse_width_blanks(&t_node);
			parse_left_just_blanks(&t_node, count);
			parse_zeroes(&t_node);
			print_it(fmt, &t_node, ap, count);
		}
		else
			ft_pputchar(*fmt, count, &t_node);
		fmt++;
	}
}

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, fmt);
	ft_cases(fmt, ap, &count);
	va_end(ap);
	return (count);
}
