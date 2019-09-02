/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:37:49 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/02 12:40:13 by jcruz-y-         ###   ########.fr       */
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
    (void) cur;
    (void) arena;
}