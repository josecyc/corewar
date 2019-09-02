/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 02:27:58 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/02 11:57:10 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"
/*
**	ft_lldi
**	opcode 0x0a, changes the carr:w
**  usage : lldi ARG_1(RG/ID/D2), ARG_2(ID/D2), ARG_3(RG)
**	same as ldi but without % IDX_MOD
**	reads REG_SIZE at the adress process->pc + (ARG_1 + ARG_2) and stores it
**	in ARG_3
**
*/

static void		inst_ld(t_player *cur, t_arena *arena)
{
    (void) cur;
    (void) arena;
}