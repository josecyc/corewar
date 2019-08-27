/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 22:04:07 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/09 21:38:41 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	signed_cases(t_elem *t_node, va_list ap, int *count)
{
	if (ft_pstrcmp(t_node->mod, "h") == 0 &&
		(t_node->type == 'd' || t_node->type == 'i'))
		return (ft_pputnbr((short)va_arg(ap, int), count, t_node));
	if (ft_pstrcmp(t_node->mod, "hh") == 0 &&
		(t_node->type == 'd' || t_node->type == 'i'))
		return (ft_pputnbr((char)va_arg(ap, int), count, t_node));
	if (ft_pstrcmp(t_node->mod, "l") == 0 &&
		(t_node->type == 'd' || t_node->type == 'i'))
		return (ft_pputnbr(va_arg(ap, long int), count, t_node));
	if (ft_pstrcmp(t_node->mod, "ll") == 0 &&
		(t_node->type == 'd' || t_node->type == 'i'))
		return (ft_pputnbr(va_arg(ap, long long int), count, t_node));
	else
		return (ft_pputnbr(va_arg(ap, int), count, t_node));
}

void	unsigned_cases(t_elem *t_node, va_list ap, int *count)
{
	if (ft_pstrcmp(t_node->mod, "h") == 0)
		return (pitoa_base((unsigned short)va_arg(ap, int), t_node, count));
	if (ft_pstrcmp(t_node->mod, "hh") == 0)
		return (pitoa_base((unsigned char)va_arg(ap, int), t_node, count));
	if (ft_pstrcmp(t_node->mod, "l") == 0)
		return (pitoa_base(va_arg(ap, unsigned long int), t_node, count));
	if (ft_pstrcmp(t_node->mod, "ll") == 0)
		return (pitoa_base(va_arg(ap, unsigned long long int), t_node, count));
	if (t_node->type == 'p')
		return (pitoa_base(va_arg(ap, unsigned long int), t_node, count));
	else
		return (pitoa_base(va_arg(ap, unsigned int), t_node, count));
}

void	float_cases(t_elem *t_node, va_list ap, int *count)
{
	if (ft_pstrcmp(t_node->mod, "l") == 0)
		return (ftoa(va_arg(ap, double), t_node->prec, count, t_node));
	if (ft_pstrcmp(t_node->mod, "L") == 0)
		return (ftoa(va_arg(ap, long double), t_node->prec,
		count, t_node));
	else
		return (ftoa(va_arg(ap, double), t_node->prec, count, t_node));
}
