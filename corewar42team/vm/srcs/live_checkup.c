/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_checkup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 09:04:14 by tholzheu          #+#    #+#             */
/*   Updated: 2019/09/09 11:32:30 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

// What happens when all processes are dead?
// The game is over
// What increases live counter?
// Whenever a process executes live
// If game finishes and 2 players got their number called by live who wins?
// the one who executes it at the end
// Every cycles_to_die we increase the arena->check up counter 
// if the arena->checkup_counter is equal to MAX_CHECKS or the live instruction has been 
// executed more than or equal to NBR_LIVE times we decrease the CYCLES_TO_DIE
// Makes sense because the game must go faster if so many live instructions
// are being executed
// this is killing processes not players 

static int	check_dead(t_player *fprocess, t_arena *arena)
{
	t_player	*cur;
	int			dead_count;
	int			proc_count;

	cur = fprocess;
	dead_count = 0;
	proc_count = 0;
	while (cur)
	{
		if (cur->dead == 1)
			dead_count++;
		if (cur->dead == 0 && cur->life_bl == 0 && ++dead_count)
			cur->dead = 1; // insert sound for bonus
		if (cur->life_bl == 1)
			cur->life_bl = 0;
		cur = cur->next;
		proc_count++;
	}
	//printf(" - - - - - - - - -\n");
	//printf("DEEAAADDDD %d\n", dead_count);
	//printf("PROC COUNT %d\n", proc_count);
	//return (-1);
	if (dead_count == proc_count)
		return (-1);
	//arena->num_plys -= count; because this is killing processes we must not reduce the players
	//arena->num_processes -= count; ??
	return (1);
}

/*
** Every CYCLE_TO_DIE we perform a checkup, where:
** 1) We increase the check_up counter by 1
** *note: every time a process executes a live inst, we increase arena_live_counter by 1
** 2) We check if the live inst has been executed NBR_LIVE times or more
** 3) Check if we have performed this checkup at this amount of cycle_to_die 
** MAX_CHECKS times
*/

// might be that we are not updating checks correctly

int			live_checkup(t_player *fprocess, t_arena *arena)
{
	if (check_dead(fprocess, arena) == -1)
		return (-1);
	if (arena->live_counter >= NBR_LIVE || arena->checkup_counter == MAX_CHECKS)
	{
		arena->cycle_to_die -= CYCLE_DELTA;
		arena->checkup_counter = 0;
	}
	arena->checkup_counter++;
	arena->cycle_counter = 0;
	arena->live_counter = 0;
	return (1);
}
