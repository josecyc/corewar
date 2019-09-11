/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_lldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:22:18 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/10 22:00:50 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		inst_lldi2(t_player *cur, t_arena *arena, int *i, int *j)
{
	int		adress;
	int		get_byte;

	adress = 0;
	get_byte = 0;
	if ((cur->inst->ebyte >> *i & 3) == REG_CODE)
	{
		if (!valid_reg_int(cur, *j))
		{
			advance_proc_pc(&cur, jump_next_op(cur->inst->op_code));
			return (0);
		}
		cur->inst->args[*j] = cur->reg[cur->inst->args[*j] - 1];
	}
	else if ((cur->inst->ebyte >> *i & 3) == DIR_CODE)
	{
		adress = get_addr_value(cur, (-cur->inst->size) + \
		(cur->inst->args[0] % IDX_MOD));
		memory_to_int(&get_byte, arena, adress, 2);
		cur->inst->args[*j] = get_byte;
	}
	*i = *i - 2;
	return (1);
}

void	inst_lldi(t_player *cur, t_arena *arena)
{
	int adress;
	int get_byte;
	int i;
	int args;

	args = -1;
	i = 6;
	if (!valid_reg_int(cur, 2) && advance_proc_pc(&cur,
	jump_next_op(cur->inst->op_code)))
		return ;
	while (i != 2 && ++args)
	{
		if (!inst_lldi2(cur, arena, &i, &args))
			return ;
	}
	adress = get_addr_value(cur, (-cur->inst->size) + \
	(cur->inst->args[0] + cur->inst->args[1]));
	memory_to_int(&get_byte, arena, adress, 4);
	cur->carry = (get_byte == 0) ? 1 : 0;
	cur->reg[cur->inst->args[2] - 1] = get_byte;
}
