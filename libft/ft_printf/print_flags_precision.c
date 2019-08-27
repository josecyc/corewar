/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:46:59 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/10 18:54:49 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	print_width(t_elem *t_node, int *count)
{
	int i;

	i = 0;
	if (t_node->type == 'c' && t_node->arg_length == 0)
		i++;
	while (i < t_node->width_blanks)
	{
		ft_pputchar(' ', count, t_node);
		i++;
	}
}

void	print_numsub_plus(t_elem *t_node, int *count)
{
	if (t_node->val_zero == 0)
	{
		if ((t_node->hashsign == 1 && t_node->type == 'x') ||
		t_node->type == 'p')
			ft_pputstr("0x", count, t_node);
		if (t_node->hashsign == 1 && t_node->type == 'X')
			ft_pputstr("0X", count, t_node);
		if (t_node->hashsign == 1 && t_node->type == 'o')
			ft_pputstr("0", count, t_node);
		if (t_node->neg_num == 0 && t_node->plus_sign == 1 &&
			(t_node->type == 'd' || t_node->type == 'i'))
			ft_pputchar('+', count, t_node);
		if (t_node->neg_num == 1 && (t_node->zero == 1 ||
		t_node->prec > t_node->arg_length)
		&& (t_node->type == 'd' || t_node->type == 'i' ||
		t_node->type == 'f'))
			ft_pputchar('-', count, t_node);
	}
}

void	print_space(t_elem *t_node, int *count)
{
	if (t_node->plus_sign == 0 && t_node->space == 1 &&
		(t_node->type == 'd' || t_node->type == 'i' ||
		t_node->type == 'f') && t_node->neg_num == 0
		&& (t_node->width <= t_node->prec || t_node->prec_bl == 0))
		ft_pputchar(' ', count, t_node);
}

void	print_precision(t_elem *t_node, int *count)
{
	int i;
	int zeroes;

	i = 0;
	zeroes = 0;
	if (t_node->arg_length > 0)
		zeroes = t_node->prec - t_node->arg_length;
	if (t_node->type != 'f' && t_node->type != 's')
	{
		while (i < zeroes)
		{
			ft_pputchar('0', count, t_node);
			i++;
		}
	}
}

void	print_zeroes(t_elem *t_node, int *count)
{
	int i;

	i = 0;
	if (t_node->type == 'c' && t_node->arg_length == 0)
		i++;
	if (t_node->prec == 0)
	{
		while (i < t_node->zeroes && t_node->zero == 1)
		{
			ft_pputchar('0', count, t_node);
			i++;
		}
	}
}
