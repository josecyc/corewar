/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 02:29:11 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/02 20:16:55 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**	opcode 0x02, changes the carry if ARG_1 is null
**  usage : ld ARG_1(ID/D4), ARG_2(RG)
**	loads the value of ARG_1 in ARG_2
**	direct transfert from RAM to register
*/

void		inst_ld(t_player *cur, t_arena *arena)
{
    cur->carry = (cur->inst->args[0] == 0)? 1 : 0;
    cur->reg[cur->inst->args[1] - 1] = (cur->inst->args[0] % IDX_MOD);
}