/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:22:26 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/03 16:47:53 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
*  Op Code number 11;
*  Take The value of the first Arg and write it to the cell of the (PC + (arg[1] + arg[2] % IDX_MOD))
*  Change The carry --> 1 if 0 ; 0 if 1.
*/
void         inst_sti(t_player *cur, t_arena *arena)
{
    unsigned char ebyte;
    int reg_value;
    int i;
    int adress;
    int indirect_cell;

    i = 24;
    indirect_cell = 0;
    reg_value = cur->reg[cur->inst->args[0] - 1];
    ebyte = cur->inst->ebyte >> 4 & 3;
    if (ebyte == DIR_CODE || ebyte == REG_CODE)
        adress = get_addres_value(cur, -cur->inst->size + (cur->inst->args[1] + cur->inst->args[2]) % IDX_MOD);
    else
    {
        adress = get_addres_value(cur, (-cur->inst->size) + (cur->inst->args[1] % IDX_MOD));
        memory_to_int(&indirect_cell, arena, adress, 4);
        adress = get_addres_value(cur, -cur->inst->size + (indirect_cell + cur->inst->args[2]) % IDX_MOD);
    }
    while (i >= 0)
    {
        arena->memory[adress] = (char)(reg_value >> i);
        adress++;
        adress = (adress == MEM_SIZE) ? 0 : adress;     
        i -= 8;        
    }
}