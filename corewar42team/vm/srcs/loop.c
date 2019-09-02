/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:55:08 by tholzheu          #+#    #+#             */
/*   Updated: 2019/09/02 15:15:24 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static t_inst_funct	inst_functions[16] =
{
	inst_live,
	inst_ld,
	inst_st,
	inst_add,
	inst_sub,
	inst_and,
	inst_or,
	inst_xor,
	inst_zjmp,
	inst_ldi,
	inst_sti,
	inst_fork,
	inst_lld,
	inst_lldi,
	inst_lfork,
	inst_aff
};

/*
** The loop consists of the main structure and mgmnt of the program,
** during each loop the cycle increases it finishes when 
** cycles_to_die have been reduced to >= 0 via or when there are no more processes 
** The cycles decrease whenever a loop is executed.
*/

void			loop(t_player *players, t_arena *arena)
{
	t_player		*cur;

	printf("cycle_to_die = %d\n", arena->cycle_to_die);
	while (arena->cycle_to_die >= 0)
	{
		cur = players;
		while (cur)
		{
			if (cur->inst->counter == -1 && save_inst(cur, arena) == -1) // if it's -1 it means to save inst
				cur->pc++;
			if (cur->inst->counter == 0)
			{
				printf("cur->inst->op_code = %d\n", cur->inst->op_code);
				inst_functions[cur->inst->op_code - 1](cur, arena);
			}
			cur->inst->counter != -1 ? cur->inst->counter-- : cur->inst->counter;
			cur = cur->next;
		}
		if (arena->cycle_counter == arena->cycle_to_die)
			if (live_checkup(players, arena) == -1)
				return ;
		//graphics(arena, players);
		//print_memory(arena->memory);
		print_info(arena, players);
		//sleep(10);
		//break;
		arena->cycle_counter++;
		arena->total_cycles++;
	}
}
