/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 02:29:11 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/03 15:41:45 by viduvern         ###   ########.fr       */
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
    int adress;
    short byte;
    int get_byte;

    if(cur->inst->size == 7)
    {
        cur->carry = (cur->inst->args[0] == 0)? 1 : 0;
        cur->reg[cur->inst->args[1] - 1] = (cur->inst->args[0] % IDX_MOD);
    }
    else
    {
        byte = (cur->inst->args[0] % IDX_MOD);
        // adress = get_addres_value(cur, -2);
        // arena->memory[adress] = (char)byte;
        // adress = get_addres_value(cur, -3);
        // arena->memory[adress] = (char)byte >> 4;
        adress = get_adress_value(cur, ((-cur->inst->size) + byte));
        memory_to_int(&get_byte, arena, adress, 4);
        cur->carry = (get_byte == 0) ? 1 : 0;
        cur->reg[cur->inst->args[1] - 1] = get_byte;
    }