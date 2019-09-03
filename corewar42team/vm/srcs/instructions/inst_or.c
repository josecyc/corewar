/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:37:49 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/02 19:53:50 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/vm.h"
/* 
**	opcode 0x07, changes carry if the result is null
**  usage : or ARG_1(RG/ID/D4), ARG_2(RG/ID/D4), ARG_3(RG)
**	applies | (bitwise or) on ARG_1 | ARG_2 and stores the result in ARG_3 reg
*/

void		inst_or(t_player *cur, t_arena *arena)
{
    int result;

    result = cur->inst->args[0] | cur->inst->args[1];
    cur->carry = (result == 0 )? 1 : 0;
    cur->reg[cur->inst->args[2] - 1] = result;
}