/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:34:12 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/06 19:27:34 by viduvern         ###   ########.fr       */
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
    t_player    *new;
    
    i = 0;
    new = create_player();
    new->pnum = player->pnum; // when checking for winner, maybe delete line?
    new->inst->fork = 1;
    while (i < REG_NUMBER)
    {
        new->reg[i] = player->reg[i];
        i++;
    }
    new->pc = player->pc;
    advance_proc_pc(&new, -player->inst->size);
    advance_proc_pc(&new, player->inst->args[0]);
    add_process_last(&player, new);
}  