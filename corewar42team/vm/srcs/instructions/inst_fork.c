/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:20:00 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/01 16:37:34 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** Fork creates a new process which inherits the same REG_NUM registers and contents
** of the parent and begins execution (pc address) where the first argument
** indicates
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

static void inst_fork(t_player *player, t_arena *arena)
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
    advance_proc_pc(new_process, player->inst->args[0] % IDX_MOD);
} 