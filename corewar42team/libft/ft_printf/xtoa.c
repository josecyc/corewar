/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:31:47 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/09 21:39:56 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void		pitoa_base(unsigned long long num, t_elem *t_node, int *count)
{
	unsigned long long	base;

	base = 10;
	if (t_node->type == 'x' || t_node->type == 'X' || t_node->type == 'p')
		base = 16;
	if (t_node->type == 'o')
		base = 8;
	if (num < base)
	{
		if (num >= 10 && num <= 15 && (t_node->type == 'x' ||
		t_node->type == 'p'))
			ft_pputchar(num + 87, count, t_node);
		else if (num >= 10 && num <= 15 && t_node->type == 'X')
			ft_pputchar(num + 55, count, t_node);
		else if (((t_node->val_zero == 0 || t_node->hashsign == 1) &&
		t_node->just_dec == 0) || (t_node->type == 'o' && t_node->just_dec == 1
		&& t_node->val_zero && t_node->hashsign == 1))
			ft_pputchar(num + '0', count, t_node);
	}
	else
	{
		pitoa_base(num / base, t_node, count);
		pitoa_base(num % base, t_node, count);
	}
}

void		itoa_blen(unsigned long long num, t_elem *t_node)
{
	unsigned long long	base;

	base = 10;
	if (t_node->type == 'x' || t_node->type == 'X')
		base = 16;
	if (t_node->type == 'o')
		base = 8;
	if (num < base)
	{
		if (num >= 10 && num <= 15 && t_node->type == 'x')
			t_node->blen++;
		else if (num >= 10 && num <= 15 && t_node->type == 'X')
			t_node->blen++;
		else
			t_node->blen++;
	}
	else
	{
		itoa_blen(num / base, t_node);
		itoa_blen(num % base, t_node);
	}
}

void		ftoa(double long fnum, long precision, int *count, t_elem *t_node)
{
	long long			ipart;
	long double			fpart;
	long long			fpart2;
	int					len;
	int					i;

	ipart = (long long)fnum;
	fpart = fnum - ipart;
	len = 1;
	i = 0;
	while ((t_node->prec == 0 && i < 6) || i < precision)
	{
		len = len * 10;
		i++;
	}
	fpart2 = fpart * len;
	fpart = fpart * len;
	fpart = ft_round(fpart);
	pitoa_base(ipart, t_node, count);
	if (t_node->just_dec == 0)
	{
		ft_pputchar('.', count, t_node);
		pitoa_base((unsigned long long)fpart, t_node, count);
	}
}

long long	ft_round(long double fpart)
{
	long long			ipart;
	long double			flpart;

	ipart = (long long)fpart;
	flpart = fpart - ipart;
	if (flpart > .5)
		ipart++;
	return (ipart);
}
