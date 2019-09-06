/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:21:56 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/05 21:38:42 by jcruz-y-         ###   ########.fr       */
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
        adress = get_addr_value(cur, (-cur->inst->size) + (cur->inst->args[1] % IDX_MOD)); 
        cur->write_addr = adress;
        while (i >= 0)
        {
            adress = (adress == MEM_SIZE) ? 0 : adress;     
            arena->memory[adress] = (char)(reg_value >> i);
            adress++;
            i -= 8;   
        }
        cur->write_bl = 1;
    }
}