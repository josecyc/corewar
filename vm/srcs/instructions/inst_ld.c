/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 02:29:11 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/09 23:51:28 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** opcode 0x02, changes the carry if ARG_1 is null
** usage : ld ARG_1(ID/D4), ARG_2(RG)
** loads the value of ARG_1 in ARG_2
** direct transfer from RAM to register
*/

void		inst_ld(t_player *cur, t_arena *arena)
{
	int		adress;
	short	byte;
	int		get_byte;
	char	ebyte;

	ebyte = cur->inst->ebyte >> 6 & 3;
	if (!valid_reg_int(cur, 1))
	{
		advance_proc_pc(&cur, jump_next_op(cur->inst->op_code));
		return ;
	}
	if (ebyte == DIR_CODE)
	{
		cur->carry = (cur->inst->args[0] == 0) ? 1 : 0;
		cur->reg[cur->inst->args[1] - 1] = (cur->inst->args[0]);
	}
	else
	{
		byte = (cur->inst->args[0] % IDX_MOD);
		adress = get_addr_value(cur, ((-cur->inst->size) + byte));
		memory_to_int(&get_byte, arena, adress, 4);
		cur->carry = (get_byte == 0) ? 1 : 0;
		cur->reg[cur->inst->args[1] - 1] = get_byte;
	}
}
