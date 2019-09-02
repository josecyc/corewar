/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_lldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:22:18 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/02 12:40:06 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"
/*
**	opcode 0x0a, changes the carry
**  usage : ldi ARG_1(RG/ID/D2), ARG_2(ID/D2), ARG_3(RG)
**	reads REG_SIZE at the adress process->pc + (ARG_1 + ARG_2) and stores it
**	in ARG_3
*/

void		inst_lldi(t_player *cur, t_arena *arena)
{
    (void) cur;
    (void) arena;

}