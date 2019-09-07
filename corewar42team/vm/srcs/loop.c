/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:55:08 by tholzheu          #+#    #+#             */
/*   Updated: 2019/09/07 11:02:39 by viduvern         ###   ########.fr       */
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

void	clean_process_inst(t_player *process)
{
	process->inst->ebyte = 0;
	process->inst->args[0] = 0;
	process->inst->args[1] = 0;
	process->inst->args[2] = 0;
	process->inst->args[2] = 0;
	process->inst->op_code = 0;
	process->inst->size = 0;
	process->inst->counter = 0;
}

/*
** The loop consists of the main structure and mgmnt of the program,
** during each loop the cycle increases it finishes when 
** cycles_to_die have been reduced to >= 0 via or when there are no more processes 
** The cycles decrease whenever a loop is executed.
*/

void			loop(t_player *players, t_arena *arena)
{
	t_player		*cur;
	t_window		*win;

	//win = init_interactive_mode();
	//printf("cycle_to_die = %d\n", arena->cycle_to_die);
	while (arena->cycle_to_die >= 0)
	{
		while(players->prev != NULL)
			players = players->prev;
		cur = players;
		while (cur)
		{
			while (cur && (cur->dead))
			{
				cur = cur->next;
			}
			if (cur)
			{
				if (cur->inst->counter == -1 && save_inst(cur, arena) == -1) // if it's -1 it means to save inst
					cur->pc++;
				if (cur && cur->inst->counter == 0)
				{
					//printf("- - - - - - - - -\n");
					//printf("EXECUTING\n");
					//printf("MNEMONIC           = %s\n", op_tab[cur->inst->op_code - 1].mnemonic);
					//printf("cur->inst->op_code = %d\n", cur->inst->op_code);
					//printf("- - - - - - - - -\n");
					if (cur->inst->ebyte != 255)
					{
						inst_functions[cur->inst->op_code - 1](cur, arena);
						//cur->pc++;
					}
					clean_process_inst(cur);
				}
				cur->inst->counter != -1 ? cur->inst->counter-- : cur->inst->counter;
				cur = cur->next;
			}
		}
		if (arena->cycle_counter == arena->cycle_to_die)
			if (live_checkup(players, arena) == -1)
				return ;
		//print_info(arena, players);
		//interactive(players, arena, win);
		//graphics(arena, players); //Victor cleans the write bl and address here
		if (arena->flags->dump_bl && arena->flags->dump_cycles == arena->total_cycles)
		{
			print_memory(arena->memory);
			break;
		}
		arena->cycle_counter++;
		arena->total_cycles++;
	}
	//close_win();
 }