/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 21:39:55 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/02 20:18:22 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
*  Op code Number 1;
*  Stipulate the process "alive" 
*  If the number stipulate in the argument it's not a Champion Number, Do nothing.
*/
void		    inst_live(t_player *cur, t_arena *arena)
{
    int number_player;

    number_player = cur->inst->args[0]; // ---> REG[0] can change during the execution, we have to save the number in another way
    if(number_player != cur->pnum)
    {
        while(cur)
        {
            if(number_player == cur->pnum)
            {
                ft_printf("A process shows that Player [%d] named [%s] is alive", number_player, cur->name);
                cur->life_bl = 1;
                arena->live_counter++;
                arena->last_alive = number_player;
                return ;
            }
            cur = cur->next;
        }
    }
    else if(number_player == cur->pnum)
    {
        cur->life_bl = 1;
        arena->live_counter++;
        arena->last_alive = number_player;
        ft_printf("A process shows that Player [%d] named [%s] is alive", number_player, cur->name);
    }
    else 
        return ;
}