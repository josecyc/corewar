/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:34:12 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/03 20:22:00 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/* 
**	opcode 0x0f
**  usage : lfork ARG_1(D2)
**	same as fork but without % IDX_MOD
**	creates a new process to be placed at the adress (PC + (ARG_1)
**	the new process inherits every state from the father
*/

void     inst_lfork(t_player *player, t_arena *arena)
{
    int         i;    
    t_player    *new_process;
    
    i = 0;
    new_process = add_process_last(&player);
    new_process->pnum = player->pnum;
    while (i < REG_NUMBER)
    {
        new_process->reg[i] = player->reg[i];
        i++;
    }
    new_process->pc = player->pc;
    advance_proc_pc(&new_process, player->inst->args[0]);
} 