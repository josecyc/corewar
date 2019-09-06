/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:20:00 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/05 21:45:03 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** op_code 12
** arg1 DIR -> indexed
** Fork creates a new process which inherits the same REG_NUM registers and
** contents of the parent and begins execution (pc address) where the first
** argument indicates
*/

t_player    *add_process_last(t_player **any_process)
{
    t_player    *elem;

    elem = *any_process;
    while (elem->next)
    {
        elem = elem->next;
    }
    elem->next = create_player();
    return (elem->next);
}

void     inst_fork(t_player *player, t_arena *arena)
{
    int         i;    
    t_player    *new_process;
    
    i = 0;
    new_process = add_process_last(&player);
    new_process->pnum = player->pnum; // when checking for winner, maybe delete line?
    new_process->inst->fork = 1;
    while (i < REG_NUMBER)
    {
        new_process->reg[i] = player->reg[i];
        i++;
    }
    new_process->pc = player->pc;
    advance_proc_pc(&new_process, -player->inst->size);
    //printf("player->pc %d\n", player->pc);
    //printf("new_process->pc %d\n", new_process->pc);
    //printf("SIZEEEE %d\n", player->inst->size);
    //printf("arg1  IDX %d\n", player->inst->args[0] % IDX_MOD);
    advance_proc_pc(&new_process, player->inst->args[0] % IDX_MOD);
    //printf("new_process->pc %d\n", new_process->pc);
} 