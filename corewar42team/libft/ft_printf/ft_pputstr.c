/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:03:22 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/01/10 18:54:51 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	ft_pputstrh(char *str, t_elem *t_node, int *count)
{
	int		i;

	i = 0;
	if (t_node->arg_length > t_node->prec || ft_pstrcmp(str, "") == 0)
	{
		while (i < t_node->prec)
		{
			if (ft_pstrcmp(str, "") == 0)
				ft_pputchar(' ', count, t_node);
			else
				ft_pputchar(str[i], count, t_node);
			i++;
		}
	}
	else
		while (i < t_node->arg_length)
		{
			ft_pputchar(str[i], count, t_node);
			i++;
		}
}

void	ft_pputstr(char *str, int *count, t_elem *t_node)
{
	int		i;

	i = 0;
	if (str == '\0')
		return (ft_pputstr("(null)", count, t_node));
	if (ft_pstrcmp(str, "") == 0 && (t_node->minus_sign == 1 ||
	t_node->width == 0))
	{
		t_node->empty = 1;
		return ;
	}
	if (t_node->prec_bl == 0)
	{
		while (str[i])
		{
			ft_pputchar(str[i], count, t_node);
			i++;
		}
	}
	else
		ft_pputstrh(str, t_node, count);
}
