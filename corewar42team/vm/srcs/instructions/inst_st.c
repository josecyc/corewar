/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:21:56 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/03 16:47:40 by viduvern         ###   ########.fr       */
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
    unsigned char ebyte;
    int reg_value;
    int i;
    int adress;

    i = 24;
    reg_value = cur->reg[cur->inst->args[0] - 1];
    ebyte = cur->inst->ebyte >> 4 & 3;
    if (ebyte == REG_CODE)
        cur->reg[cur->inst->args[1] - 1] = reg_value;      
    else
    {
        adress = get_addres_value(cur, (-cur->inst->size) + (cur->inst->args[0] % IDX_MOD));
        while (i >= 0)
        {
            arena->memory[adress] = (char)(reg_value >> i);
            adress++;
            i -= 8;   
            adress = (adress == MEM_SIZE) ? 0 : adress;     
        }
    }
}