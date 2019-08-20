/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:30:46 by tholzheu          #+#    #+#             */
/*   Updated: 2019/01/26 19:10:46 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int	get_address(char *str, t_vars *ob, int arg)
{
	t_label *temp;
	size_t	len;

	temp = ob->labels;
	while (temp)
	{
		len = ft_strlen(str);
		if (len + 1 == ft_strlen(temp->label) &&
				ft_strncmp(str, temp->label, len) == 0)
			return (temp->address);
		temp = temp->next;
	}
	return (error_message(12, ob->counter, arg));
}

int			print_direct(char *param, t_vars *ob, int begin_address, int arg)
{
	int		num;

	param = param + 1;
	if (param[0] == LABEL_CHAR)
	{
		if ((num = get_address(param + 1, ob, arg)) == -1)
			return (-1);
		num = num - begin_address;
	}
	else
		num = ft_atoi(param);
	byte_print(num, 4, ob->output_fd);
	return (1);
}

int			print_indirect(char *param, t_vars *ob, int begin_address, int arg)
{
	int		num;

	if (param[0] == DIRECT_CHAR)
		param = param + 1;
	if (param[0] == LABEL_CHAR)
	{
		if ((num = get_address(param + 1, ob, arg)) == -1)
			return (-1);
		num = num - begin_address;
	}
	else
		num = ft_atoi(param);
	byte_print(num, 2, ob->output_fd);
	return (1);
}
