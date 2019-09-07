/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:20:00 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/06 17:12:50 by viclucas         ###   ########.fr       */
/*   Updated: 2019/09/07 15:53:22 by viduvern         ###   ########.fr       */
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
    t_player *tmp;

    tmp = *any_process;
    int i  = 0 ;
    new = create_player();
    tmp->inst->fork = 1;
    new->pnum = tmp->pnum;
    new->carry = tmp->carry;
    new->life_bl = tmp->life_bl;
    new->name = tmp->name;
    new->pc_inter = tmp->pc_inter;
    new->dead = new->dead;
    while (i < REG_NUMBER)
    {
        new->reg[i] = tmp->reg[i];
        i++;
    }
    new->pc = tmp->pc;
    advance_proc_pc(&new, (-tmp->inst->size) + (tmp->inst->args[0] % IDX_MOD));

    while(tmp->prev)
    {
        tmp = tmp->prev;
        i++;
    }
    tmp->prev = new;
    new->next = tmp;
    //*any_process;
  //  (*any_process) = new;
    return(*any_process);
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
