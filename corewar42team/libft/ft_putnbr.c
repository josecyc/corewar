/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 21:38:47 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/19 20:12:06 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_neg(int *nb)
{
	ft_putchar('-');
	if (*nb == -2147483648)
	{
		ft_putchar('2');
		*nb = 147483648;
	}
	else
		*nb = *nb * (-1);
}

void		ft_putnbr(int nb)
{
	int	highest_power;
	int	num_to_print;

	highest_power = 10;
	if (nb < 0)
		ft_print_neg(&nb);
	while ((nb % highest_power) != nb && (highest_power != 1000000000))
		highest_power = highest_power * 10;
	if (nb >= 1000000000)
		ft_putchar(48 + nb / highest_power);
	while (highest_power != 1)
	{
		num_to_print = 48 + (nb % highest_power) / (highest_power / 10);
		ft_putchar(num_to_print);
		highest_power = highest_power / 10;
	}
}
