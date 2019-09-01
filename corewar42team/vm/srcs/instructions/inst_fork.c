/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:20:00 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/01 16:03:47 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** Fork creates a new process which inherits the same REG_NUM registers and contents
** of the parent and begins execution (pc address) where the first argument
** indicates
*/

static void inst_fork(t_player *player, t_arena *arena)
{
    int         i;    
    t_player    *new_process;
    
    i = 0;
    new_process = create_player();
    new_process->pnum = player->pnum;
    while (i < REG_NUMBER)
    {
        new_process->reg[i] = player->reg[i];
        i++;
    }
    advance_proc_pc(player, player->inst->args[0]);
    if ((player->pc + player->inst->args[0]) >= MEM_SIZE)
        new_process->pc = player->pc + player->inst->args[0] - MEM_SIZE;
    else
        new_process->pc = player->inst->args[0];
}   