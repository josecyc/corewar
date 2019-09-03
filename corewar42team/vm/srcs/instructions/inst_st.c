/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:21:56 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/02 19:47:16 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*	
**	opcode 0x03
**  usage : st ARG_1(RG), ARG_2(RG/ID)
**	stores ARG_1 in reg ARG_2 or at ind ARG_2
**  Op Code number 3;
**
 */
void         inst_st(t_player *cur, t_arena *arena)
{
    char arg_type;
    int move_pc;
    int byte;
    int i;

    i = 24;
    byte = cur->reg[cur->inst->args[0] - 1];
    arg_type = cur->inst->ebyte >> 4 & 3;
    if(arg_type == REG_CODE)
        cur->reg[cur->inst->args[1] - 1] = cur->reg[cur->inst->args[0] - 1];      
    else
    {
       advance_proc_pc(&cur, -3); 
       move_pc = (cur->pc + (cur->inst->args[1] % IDX_MOD));
        while (i >= 0)
        {
            arena->memory[move_pc] = (char)(byte >> i);
            move_pc++;
            i -= 8;        
        }
        advance_proc_pc(&cur, 3);
    }
}