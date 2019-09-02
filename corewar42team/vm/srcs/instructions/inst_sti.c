/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:22:26 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/01 18:13:00 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
*  Op Code number 11;
*  Take The value of the first Arg and write it to the cell of the (PC + (arg[1] + arg[2] % IDX_MOD))
*  Change The carry --> 1 if 0 ; 0 if 1.
*/
static void         inst_sti(t_player *cur, t_arena *arena)
{
    char arg_type;
    int move_pc;
    int byte;
    int i;

    i = 24;
    byte = cur->inst->args[0];
    // move_pc = 1;     
    // arg_type = cur->inst->ebyte >> 4 & 3;

//    cur->carry = (cur->carry == 1) ? 0 : 1;
    // move_pc += (arg_type == REG_CODE) ? 1 : 2;
    // arg_type = cur->inst->ebyte >> 2 & 3;
    // move_pc += (arg_type == REG_CODE) ? 1 : 2;
    move_pc = ((cur->inst->args[1] + cur->inst->args[2]) % IDX_MOD);
    while (i >= 0)
    {
        arena->memory[move_pc] = (char)(byte >> i);
        move_pc++;
        i -= 8;        
    }
}