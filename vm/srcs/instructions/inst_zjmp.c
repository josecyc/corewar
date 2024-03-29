/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 17:19:06 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/09 14:11:06 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**  Op code Number 9;
**  Jump If carry == 1 ;
**  Jump thru the next adress from the pc +
**  the index stipulate in the argument % IDX_MOD;
**  If carry == 0 --> Do nothing.
*/

void		inst_zjmp(t_player *cur, t_arena *arena)
{
	(void)arena;
	if (cur->carry == 0)
		return ;
	else
		advance_proc_pc(&cur, (-cur->inst->size) + \
		cur->inst->args[0] % IDX_MOD);
}
