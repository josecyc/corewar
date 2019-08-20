/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:28:24 by tholzheu          #+#    #+#             */
/*   Updated: 2019/01/26 18:51:26 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int		check_arglabel(char *lbl)
{
	int		i;

	i = 1;
	if (lbl[i] == '\0')
		return (-1);
	while (lbl[i])
	{
		if (!ft_strchr(LABEL_CHARS, lbl[i]))
			return (-1);
		i++;
	}
	return (1);
}

int				check_register(char *reg, int arg_types, t_vars *ob, int arg)
{
	int		reg_num;

	if ((T_REG & arg_types) != T_REG)
		return (error_message(7, ob->counter, arg - ob->bl_label));
	reg_num = ft_atoi(reg + 1);
	if (reg_num == 0 && reg[1] != '0')
		return (error_message(8, ob->counter, arg - ob->bl_label));
	if (reg_num > REG_NUMBER || reg_num <= 0)
		return (error_message(9, ob->counter, arg - ob->bl_label));
	return (1);
}

int				check_direct(char *direct, int arg_types, t_vars *ob, int arg)
{
	if ((T_DIR & arg_types) != T_DIR)
		return (error_message(7, ob->counter, arg - ob->bl_label));
	if (direct[1] == LABEL_CHAR)
	{
		if (check_arglabel(direct + 1) == -1)
			return (error_message(10, ob->counter, arg - ob->bl_label));
	}
	else if (ft_atoi(direct + 1) == 0 && direct[1] != '0')
		return (error_message(8, ob->counter, arg - ob->bl_label));
	return (0);
}

int				check_indirect(char *ind, int arg_types, t_vars *ob, int arg)
{
	if ((T_IND & arg_types) != T_IND)
		return (error_message(7, ob->counter, arg - ob->bl_label));
	if (ind[0] == LABEL_CHAR && check_arglabel(ind) == -1)
		return (error_message(10, ob->counter, arg - ob->bl_label));
	else if (ind[0] == LABEL_CHAR)
		return (1);
	else if (ft_atoi(ind) == 0 && ind[0] != '0')
		return (error_message(8, ob->counter, arg - ob->bl_label));
	return (1);
}
