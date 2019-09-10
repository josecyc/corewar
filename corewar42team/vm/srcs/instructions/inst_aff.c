/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:27:56 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/09 23:19:15 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** ft_aff
** opcode 0x10 --> N°16
** usage : aff ARG_1(RG)
** displays the character of which the ASCII code (%256) is stored in ARG_1
*/

void		inst_aff(t_player *cur, t_arena *arena)
{
	unsigned char c;

	(void)arena;
	if (cur->inst->args[0] < REG_NUMBER && cur->inst->args[0] > 0)
	{
		c = ((unsigned char)cur->reg[cur->inst->args[0] - 1] % 256);
		write(1, &c, 1);
	}
	else
		advance_proc_pc(&cur, jump_next_op(cur->inst->op_code));
}
