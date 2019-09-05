/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:10:29 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/04 21:09:13 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** OP_Code Number 6;
** Change carry if the result is null
** Usage : ARG_1(REG/IND/DIR) ARG2(REG/IND/DIR) ARG3(REG)
** Applies & (bitwise and) on ARG_1 & ARG_2 and stores the result in ARG_3 reg
*/

void		inst_and(t_player *cur, t_arena *arena)
{
    int     res[2] = { 0 };
    int     addrs[2] = { 0 };
    short   byte[2] = { 0 };
    int     result;

    if ((cur->inst->ebyte >> 6 & 3) == IND_CODE)
    {
        byte[0] = (cur->inst->args[0] % IDX_MOD);
        addrs[0] = get_addr_value(cur, (-cur->inst->size) + byte[0]);
        memory_to_int(&res[0], arena, addrs[0], 4);
    }
    if ((cur->inst->ebyte >> 6 & 3) == REG_CODE)
    {
        res[0] = cur->reg[cur->inst->args[0]];
    }
    if ((cur->inst->ebyte >> 4 & 3) == IND_CODE)
    {
        byte[1] = (cur->inst->args[0] % IDX_MOD);
        addrs[1] = get_addr_value(cur, (-cur->inst->size) + byte[1]);
        memory_to_int(&res[1], arena, addrs[1], 4);
    }
    if ((cur->inst->ebyte >> 4 & 3) == REG_CODE)
    {
        res[1] = cur->reg[cur->inst->args[1]];
    }
    result = cur->inst->args[0] & cur->inst->args[1];
    cur->carry = (result == 0 ) ? 1 : 0;
    cur->reg[cur->inst->args[2] - 1] = result;
}