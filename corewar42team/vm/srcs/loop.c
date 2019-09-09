/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:55:08 by tholzheu          #+#    #+#             */
/*   Updated: 2019/09/09 16:01:59 by viclucas         ###   ########.fr       */
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

void	winner_print(t_player *p, t_arena *arena, t_window *win)
{
	t_player *tmp;

	tmp = p;
	wattron(win->down, COLOR_PAIR(3));
	while (tmp)
	{
		if (tmp->pnum == arena->last_alive)
		{
			mvwprintw(win->down, 3, 170, "WINNER IS \"%s\"", tmp->name);
			wattroff(win->down, COLOR_PAIR(3));
			wrefresh(win->down);
			getch_theses(win, 1);
			return ;
		}
		tmp = tmp->next;
	}
	mvwprintw(win->down, 3, 170, "END OF THE GAME");
	wrefresh(win->down);
	wattroff(win->down, COLOR_PAIR(3));
	getch_theses(win, 1);
}

void			loop(t_player *players, t_arena *arena)
{
	t_player		*cur;

	t_window		win;
	init_interactive_mode(&win);
	t_player		*tmp;

	while (arena->cycle_to_die >= 0)
	{
		cur = players;
		while (cur)
		{
			while(cur && cur->dead == 1)
				cur = cur->next;
			if(!cur)
				break ;
			if (cur->inst->counter == -1)
				while(put_cycle(cur, arena) == 0)
					cur->pc++;
			if (cur && cur->inst->counter == 0)
			{
				if(save_inst(cur, arena) != -1)
					inst_functions[cur->inst->op_code - 1](cur, arena);
				if(cur->inst->fork == 1)
				{
					cur->inst->fork = 0;
					tmp = cur;
					while(tmp->prev)
						tmp = tmp->prev;
					players = tmp;
				}
				else
					clean_process_inst(cur);
			}
			cur->inst->counter != -1 ? cur->inst->counter-- : cur->inst->counter;
			cur = cur->next;
		}	
		if (arena->cycle_counter == arena->cycle_to_die)
			if (live_checkup(players, arena) == -1)
			{
				return ;
			}
				//print_info(arena, players);
		interactive(players, arena, &win);
		//graphics(arena, players); //Victor cleans the write bl and address here
	if (arena->flags->dump_bl && arena->flags->dump_cycles == arena->total_cycles)
	{
		print_memory(arena->memory);
		return;
	}
	//close_win();
	arena->cycle_counter++;
	arena->total_cycles++;
	}
	winner_print(players, arena, &win);
	close_win();
}
