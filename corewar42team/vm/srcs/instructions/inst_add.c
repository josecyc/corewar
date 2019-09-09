/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:27:39 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/08 19:40:29 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/* 
**	opcode 0x04, changes carry if the result is null
**	usage : add ARG_1(RG), ARG_2(RG), ARG_3(RG), key 54
**	adds the value in ARG_1 to the value in ARG_2 and puts it in ARG_3
*/

void		inst_add(t_player *cur, t_arena *arena)
{
    int result;
    int i;

    i = 0;
    result = (cur->reg[cur->inst->args[0] - 1] + cur->reg[cur->inst->args[1] - 1]);
    cur->carry = (result == 0) ? 1 : 0;
    cur->reg[cur->inst->args[2] - 1] = result;  
}