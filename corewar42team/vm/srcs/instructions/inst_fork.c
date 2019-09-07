/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:20:00 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/07 12:07:13 by viduvern         ###   ########.fr       */
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

t_player        *add_process_last(t_player **any_process)
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
    advance_proc_pc(&new, (*any_process)->inst->args[0] % IDX_MOD);

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

void     inst_fork(t_player *player, t_arena *arena)
{

    t_player    *new;
 //   t_player        *tmp; 
//    tmp = player;
    //  while(tmp)
    // {
    //     if(tmp->next != NULL)
    //         x++;
    //     tmp = tmp->next;
    // }  
    new = add_process_last(&player);
    //  tmp = player;
    //  while(tmp)
    // {
    //     if(tmp->next != NULL)
    //         x++;
    //     tmp = tmp->next;
    // } 
    // printf("--------------[%d]-----------------\n", x);
    // x = 0;
    // add_process_last(&player, new);
    // tmp = player;
    // while(tmp)
    // {
    //     if(tmp->next != NULL)
    //         x++;
    //     tmp = tmp->next;
    // }
    // player = player->next;
    // printf("--------------[%d]-----------------\n", x);
} 