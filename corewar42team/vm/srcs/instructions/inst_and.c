/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:57:14 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/01 19:16:01 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** OP_Code Number 6;
** Change carry if the result is null
** Usage : ARG_1(REG/IND/DIR) ARG2(REG/IND/DIR) ARG3(REG)
** Applies & (bitwise and) on ARG_1 & ARG_2 and stores the result in ARG_3 reg
*/
static void		inst_and(t_player *cur, t_arena *arena)
{
    int result;

    result = cur->inst->args[0] & cur->inst->args[1];
    if(result == 0)
        cur->carry = (cur->carry == 0 )? 1 : 0;
    advance_proc_pc(&cur, (-1));
    cur->reg[cur->inst->args[2]] = result;
}