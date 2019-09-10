/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:30:23 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/10 00:10:35 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** opcode 0x05, changes carry if the result is null
** usage : add ARG_1(RG), ARG_2(RG), ARG_3(RG), key 54
** substract the value in ARG_1 to the value in ARG_2 and puts it in ARG_3
*/

void		inst_sub(t_player *cur, t_arena *arena)
{
	int result;
	int i;

	(void)arena;
	i = 0;
	if (valid_reg_int(cur, 4) == 1)
	{
		result = (cur->reg[cur->inst->args[0] - 1] - \
		cur->reg[cur->inst->args[1] - 1]);
		cur->carry = (result == 0) ? 1 : 0;
		cur->reg[cur->inst->args[2] - 1] = result;
	}
	else
	{
		advance_proc_pc(&cur, jump_next_op(cur->inst->op_code));
	}
}
