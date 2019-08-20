/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_blanks_zeroes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:07:42 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/10 18:55:00 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int		assign_blanks(t_elem *t_node)
{
	int		i;

	i = t_node->width;
	if (t_node->width > 0)
	{
		if (t_node->neg_num == 1 &&
		(t_node->type == 'd' || t_node->type == 'i'))
			i--;
		if (t_node->hashsign == 1 &&
		(t_node->type == 'X' || t_node->type == 'x'))
			i -= 2;
		if (t_node->hashsign == 1 &&
		(t_node->type == 'o'))
			i -= 1;
		if (t_node->plus_sign == 1 &&
		(t_node->type == 'd' || t_node->type == 'i') && t_node->neg_num == 0)
			i--;
	}
	return (i);
}

void	parse_width_blanks(t_elem *t_node)
{
	int		num_blanks;

	num_blanks = 0;
	if (t_node->minus_sign == 1 || (t_node->zero == 1 && t_node->prec == 0))
	{
		num_blanks = 0;
		return ;
	}
	num_blanks = assign_blanks(t_node);
	if ((t_node->prec_bl == 1 && t_node->prec > t_node->arg_length &&
	t_node->type != 's') || (t_node->type == 's' && t_node->arg_length == 0)
	|| t_node->space == 1)
		t_node->width_blanks = num_blanks - (t_node->prec - t_node->arg_length)
	- t_node->arg_length + t_node->val_zero;
	else
		t_node->width_blanks = num_blanks - t_node->arg_length +
		t_node->val_zero;
}

void	parse_zeroes(t_elem *t_node)
{
	int		num_zeroes;

	num_zeroes = 0;
	if (t_node->minus_sign == 1)
		return ;
	if (t_node->prec == 0 && t_node->zero == 1)
	{
		num_zeroes = t_node->width;
		if (t_node->hashsign == 1 &&
		(t_node->type == 'x' || t_node->type == 'X'))
			num_zeroes = num_zeroes - 2;
		if (t_node->hashsign == 1 && (t_node->type == 'o'))
			num_zeroes = num_zeroes - 1;
		if ((t_node->plus_sign == 1 || t_node->neg_num == 1) &&
			(t_node->type == 'd' || t_node->type == 'i'))
			num_zeroes = num_zeroes - 1;
		t_node->zeroes = num_zeroes - t_node->arg_length + t_node->val_zero -
		t_node->space;
	}
}

void	parse_left_just_blanks(t_elem *t_node, int *count)
{
	int		num_l_blanks;

	num_l_blanks = 0;
	(void)count;
	if (t_node->minus_sign == 1)
		num_l_blanks = t_node->width;
	num_l_blanks = assign_blanks(t_node);
	if (t_node->prec_bl == 1)
		t_node->left_blanks = num_l_blanks - t_node->prec + t_node->val_zero;
	else
		t_node->left_blanks = num_l_blanks - t_node->arg_length +
		t_node->val_zero;
}
