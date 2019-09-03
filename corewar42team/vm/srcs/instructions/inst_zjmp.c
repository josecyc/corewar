/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 17:19:06 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/02 16:59:53 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
*  Op code Number 9;
*  Jump If carry == 1 ; 
*   Jump thru the next adress from the pc + the index stipulate in the argument % IDX_MOD;
*   If carry == 0 --> Do nothing.
*/
void     inst_zjmp(t_player *cur, t_arena *arena)
{ 
    if(cur->carry != 0)
        return ;
    else 
    {
        advance_proc_pc(&cur, (-2));
        advance_proc_pc(&cur, cur->inst->args[0] % IDX_MOD);
    }
}
