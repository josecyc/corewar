/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 02:27:58 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/04 21:40:15 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"
/*
**	opcode 10, changes the carry
**  usage : ldi ARG_1(RG/ID/D2), ARG_2(REG/D2), ARG_3(RG)
**	reads REG_SIZE at the adress process->pc + (ARG_1 + ARG_2) and stores it
**	in ARG_3
*/

void		inst_ldi(t_player *cur, t_arena *arena)
{
    int adress;
    int get_byte;
    int i;
    int args;

    args = 0;
    i = 6;
    while(i != 2)
    {
        if (cur->inst->ebyte >> i & 3 == DIR_CODE) 
            ;
        else if(cur->inst->ebyte >> i & 3 == REG_CODE)
            cur->inst->args[args] = cur->reg[cur->inst->args[args] - 1];
        else
        {
            adress = get_addr_value(cur, (-cur->inst->size) + (cur->inst->args[0] % IDX_MOD));
            memory_to_int(&get_byte, arena, adress, 2);
            cur->inst->args[args] = get_byte;
        }
        args++;
        i -= 2;
    }
    adress = get_addr_value(cur, (-cur->inst->size) + ((cur->inst->args[0] + cur->inst->args[1]) % IDX_MOD));
    memory_to_int(&get_byte, arena, adress, 4);
    cur->reg[cur->inst->args[2] - 1] = get_byte;    
}
