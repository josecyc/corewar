/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:20:00 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/08/31 15:49:24 by jcruz-y-         ###   ########.fr       */
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
    t_player *new_process;
    
    new_process = create_player();
    new_process->pnum = player->pnum;
    new_process->reg[]

}