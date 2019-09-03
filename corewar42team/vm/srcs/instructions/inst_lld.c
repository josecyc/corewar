/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_lld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:22:12 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/03 15:44:11 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/* 
**	opcode 0x0d, changes carry
**  usage : lld ARG_1(ID/DI), ARG_2(RG)
**	same as load but without % IDX_MOD
**	loads the value of ARG_1 in ARG_2
*/

void		inst_lld(t_player *cur, t_arena *arena)
{
    int adress;
    short byte;
    int get_byte;

    byte = (cur->reg[cur->inst->args[1] - 1]);
    if(cur->inst->size == 7)
    {
        cur->carry = (cur->inst->args[0] == 0)? 1 : 0;
        cur->reg[cur->inst->args[1] - 1] = (cur->inst->args[0]);
    }
    else
    {
        // adress = get_addres_value(cur, -2);
        // arena->memory[adress] = (char)byte;
        // adress = get_addres_value(cur, -3);
        // arena->memory[adress] = (char)byte >> 4;
        adress = get_adress_value(cur, ((-cur->inst->size) + byte));
        memory_to_int(&get_byte, arena, adress, 2);
        cur->carry = (get_byte == 0) ? 1 : 0;
        cur->reg[cur->inst->args[1] - 1] = (short)get_byte;
    }
}