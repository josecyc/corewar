/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:13:15 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/09 11:20:21 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** Jump thru the Next Op
*/

int			jump_next_op(int nbr)
{
	if (nbr == 1 || nbr == 9 || nbr == 12 || nbr == 15 || nbr == 16)
		return (1);
	else if (nbr == 2 || nbr == 3 || nbr == 13)
		return (2);
	else if (nbr == 4 || nbr == 5 || nbr == 6 || nbr == 7 || \
		nbr == 8 || nbr == 10 || nbr == 11 || nbr == 14)
		return (3);
	return (0);
}

int			put_cycle(t_player *player, t_arena *arena)
{
	player->inst->op_code = (char)arena->memory[player->pc];
	if (player->inst->op_code < 1 || player->inst->op_code > 17)
		return (0);
	else
	{
		player->inst->counter = \
		op_tab[player->inst->op_code - 1].num_cycles - 1;
		return (1);
	}
}

int			advance_proc_pc(t_player **player, int step)
{
	if (((*player)->pc + step) >= MEM_SIZE)
		(*player)->pc = ((*player)->pc + step) % MEM_SIZE;
	else if (((*player)->pc + step) < 0)
		(*player)->pc = MEM_SIZE - (((*player)->pc - step) % MEM_SIZE);
	else
		(*player)->pc += step;
	return (1);
}
