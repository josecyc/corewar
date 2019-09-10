/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:55:08 by tholzheu          #+#    #+#             */
/*   Updated: 2019/09/09 16:54:42 by jcruz-y-         ###   ########.fr       */
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
	getch_theses(win, 1);
	mvwprintw(win->down, 3, 170, "END OF THE GAME");
	wrefresh(win->down);
	wattroff(win->down, COLOR_PAIR(3));
}

void	saving_inst(t_player *cur, t_arena *arena, t_player **head)
{
	t_player *tmp;


	if(save_inst(cur, arena) != -1)
		inst_functions[cur->inst->op_code - 1](cur, arena);
	if(cur->inst->fork == 1)
	{
		cur->inst->fork = 0;
		tmp = cur;
		while(tmp->prev)
			tmp = tmp->prev;	
		*head = tmp;
	}
	else
		clean_process_inst(cur);
}


void		loop2(t_player *cur, t_arena *arena, t_player **head)
{
	while (cur)
	{
		while(cur && cur->dead == 1)
			cur = cur->next;
		if(!cur)
			break;
		if (cur->inst->counter == -1)
			while(put_cycle(cur, arena) == 0)
				cur->pc++;
		if (cur && cur->inst->counter == 0)
		{
			saving_inst(cur, arena, head);
		}
	cur->inst->counter != -1 ? cur->inst->counter-- : cur->inst->counter;
	cur = cur->next;
	}
}

void	loop(t_player *players, t_arena *arena)
{
	t_player		*cur;
	t_window		win;

	if (arena->flags->interactive)
		init_interactive_mode(&win);
	while (arena->cycle_to_die >= 0)
	{
		cur = players;
		loop2(cur, arena, &players);
		if (arena->cycle_counter == arena->cycle_to_die)
			if (live_checkup(players, arena) == -1)
				return ;
		if (arena->flags->interactive)
			interactive(players, arena, &win);
		if (arena->flags->dump_bl && arena->flags->dump_cycles == arena->total_cycles)
		{
			print_memory(arena->memory);
			return;
		}
		arena->cycle_counter++;
		arena->total_cycles++;
	}
	close_win();
}
