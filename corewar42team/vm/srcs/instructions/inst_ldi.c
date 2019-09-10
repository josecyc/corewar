/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 02:27:58 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/09 23:59:08 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**  opcode 10, changes the carry
**  usage : ldi ARG_1(RG/ID/D2), ARG_2(REG/D2), ARG_3(RG)
**  reads REG_SIZE at the adress process->pc + (ARG_1 + ARG_2) and stores it
**  in ARG_3
*/

static void		inst_ldi2(t_player *cur, t_arena *arena)
{
	int result;
	int adress;
	int get_byte;

	get_byte = 0;
	result = (cur->inst->args[0] + cur->inst->args[1]) % IDX_MOD;
	adress = get_addr_value(cur, (-cur->inst->size) + result);
	memory_to_int(&get_byte, arena, adress, 4);
	cur->reg[cur->inst->args[2] - 1] = get_byte;
}

void			inst_ldi(t_player *cur, t_arena *arena)
{
	int adress;
	int get_byte;
	int i;
	int args;
	int result;

	get_byte = 0;
	args = 0;
	i = 6;
	if (!valid_reg_int(cur, 2))
	{
		advance_proc_pc(&cur, jump_next_op(cur->inst->op_code));
		return ;
	}
	while (i > 2)
	{
		if ((cur->inst->ebyte >> i & 3) == REG_CODE)
		{
			if (!valid_reg_int(cur, args))
			{
				advance_proc_pc(&cur, jump_next_op(cur->inst->op_code));
				return ;
			}
			cur->inst->args[args] = cur->reg[cur->inst->args[args] - 1];
		}
		else if ((cur->inst->ebyte >> i & 3) == IND_CODE)
		{
			result = (cur->inst->args[0] % IDX_MOD);
			adress = get_addr_value(cur, (-cur->inst->size));
			memory_to_int(&get_byte, arena, adress, 4);
			cur->inst->args[args] = get_byte;
		}
		args++;
		i -= 2;
	}
	inst_ldi2(cur, arena);
}
