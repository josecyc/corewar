/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_xor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:37:45 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/10 16:22:01 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** opcode 0x08, changes carry if the result is null
** usage : xor ARG_1(RG/ID/D4), ARG_2(RG/ID/D4), ARG_3(RG)
** applies ^ (bitwise or exclusif) on ARG_1 ^ ARG_2
** and stores the result in ARG_3 reg
*/

int			inst_xor_pt2(t_player *cur, t_arena *arena, int *i, int *j)
{
	if ((cur->inst->ebyte >> *i & 3) == IND_CODE)
	{
		memory_to_int(&cur->inst->args[*j], arena,\
		(get_addr_value(cur, (-cur->inst->size) + (cur->inst->args[*j] % IDX_MOD))), 4);
	}
	else if ((cur->inst->ebyte >> *i & 3) == REG_CODE)
	{
		if (valid_reg_int(cur, cur->inst->args[*j]))
			cur->inst->args[*j] = cur->reg[cur->inst->args[*j] - 1];
		else
		{
			advance_proc_pc(&cur, jump_next_op(cur->inst->op_code));
			return (0);
		}
	}
	*i -= 2;
	*j = *j + 1;
	return (1);
}

void		inst_xor(t_player *cur, t_arena *arena)
{
	int			j;
	int			i;

	j = 0;
	i = 6;
	while (i != 2)
	{
		if (!inst_xor_pt2(cur, arena, &i, &j))
			break;
	}
	cur->carry = ((cur->inst->args[0] ^ cur->inst->args[1]) == 0) ? 1 : 0;
	cur->reg[cur->inst->args[2] - 1] = (cur->inst->args[0] ^ cur->inst->args[1]);
}
