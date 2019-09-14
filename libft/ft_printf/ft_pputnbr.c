/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:24:24 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/09 21:39:45 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void		ft_pputnbr(long long nb, int *count, t_elem *t_node)
{
	if (nb == 0 && t_node->prec == 0 && t_node->just_dec == 1)
		return ;
	if (nb < 0)
	{
		if (nb < -9223372036854775807)
			return (ft_pputstr("-9223372036854775808", count, t_node));
		nb = -nb;
		if ((t_node->zero == 0 && t_node->prec < t_node->arg_length) ||
		t_node->neg_num == 0)
			ft_pputchar('-', count, t_node);
	}
	if (nb < 10)
	{
		nb = nb + '0';
		ft_pputchar(nb, count, t_node);
	}
	else
	{
		ft_pputnbr(nb / 10, count, t_node);
		ft_pputnbr(nb % 10, count, t_node);
	}
}
