/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_xor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:37:45 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/02 20:21:40 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/vm.h"
/* 
**	opcode 0x08, changes carry if the result is null
**  usage : xor ARG_1(RG/ID/D4), ARG_2(RG/ID/D4), ARG_3(RG)
**	applies ^ (bitwise or exclusif) on ARG_1 ^ ARG_2
**	and stores the result in ARG_3 reg
*/
void		inst_xor(t_player *cur, t_arena *arena)
{
    int result;

    result = cur->inst->args[0] ^ cur->inst->args[1];
    cur->carry = (result == 0 )? 1 : 0;
    cur->reg[cur->inst->args[2] - 1] = result;
}