/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv_dec_blanks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:25:50 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/10 18:54:47 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	print_blanks_just_left(t_elem *t_node, int *count)
{
	int		i;

	i = 0;
	if (t_node->minus_sign == 1)
	{
		while (i < t_node->left_blanks)
		{
			ft_pputchar(' ', count, t_node);
			i++;
		}
	}
	i = t_node->counter;
	if (t_node->empty == 1)
		i = 0;
	if (t_node->minus_sign == 1 && t_node->prec_bl == 1 && t_node->width > 0)
	{
		while (i < t_node->prec)
		{
			ft_pputchar(' ', count, t_node);
			i++;
		}
	}
}

void	print_conversion(t_elem *t_node, int *count, va_list ap)
{
	if (t_node->type == 'd' || t_node->type == 'i')
		signed_cases(t_node, ap, count);
	else if (t_node->type == 'x' || t_node->type == 'X' || t_node->type == 'o'
	|| t_node->type == 'u' || t_node->type == 'p')
		unsigned_cases(t_node, ap, count);
	else if (t_node->type == 'f')
		float_cases(t_node, ap, count);
	else if (t_node->type == 'c')
		ft_pputchar(va_arg(ap, int), count, t_node);
	else if (t_node->type == 's')
		ft_pputstr(va_arg(ap, char *), count, t_node);
	else if (t_node->type == '%')
		ft_pputchar('%', count, t_node);
}
