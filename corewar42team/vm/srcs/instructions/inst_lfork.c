/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:34:12 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/07 13:19:24 by viduvern         ###   ########.fr       */
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
static t_player        *add_process(t_player **any_process)
{
    t_player *new;

    int i  = 0 ;
    new = create_player();
    new->inst->fork = 1;
    new->pnum = (*any_process)->pnum;
    new->carry = (*any_process)->carry;
    new->life_bl = (*any_process)->life_bl;
    new->name = (*any_process)->name;
    while (i < REG_NUMBER)
    {
        new->reg[i] = (*any_process)->reg[i];
        i++;
    }
    new->pc = (*any_process)->pc;
    advance_proc_pc(&new, -(*any_process)->inst->size);
    advance_proc_pc(&new, (*any_process)->inst->args[0]);

    while((*any_process)->prev)
    {
        (*any_process) = (*any_process)->prev;
        i++;
    }
    (*any_process)->prev = new;
    new->next = (*any_process);
  //  (*any_process) = new;
    return(new);
}

void     inst_lfork(t_player *player, t_arena *arena)
{
        
    t_player    *new;
   new = add_process(&player); 
  
}  