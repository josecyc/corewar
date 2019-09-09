/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:34:12 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/09 14:28:34 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** opcode 0x0f
** usage : lfork ARG_1(D2)
** name as fork but without % IDX_MOD
** creates a new process to be placed at the adress (PC + (ARG_1)
** the new process inherits every state from the father
*/

static void			new_process(t_player **new, t_player *tmp)
{
	int i;

	i = 0;
	*new = create_player();
	(*new)->pnum = tmp->pnum;
	(*new)->carry = tmp->carry;
	(*new)->life_bl = tmp->life_bl;
	(*new)->name = tmp->name;
	(*new)->pc_inter = tmp->pc_inter;
	(*new)->pc = tmp->pc;
	while (i < REG_NUMBER)
	{
		(*new)->reg[i] = tmp->reg[i];
		i++;
	}
}

static t_player		*add_process_last(t_player **any_process, t_arena *arena)
{
	t_player *new;
	t_player *tmp;

	tmp = *any_process;
	new_process(&new, tmp);
	(*any_process)->inst->fork = 1;
	advance_proc_pc(&new, (-tmp->inst->size) + (tmp->inst->args[0]));
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = new;
	new->next = tmp;
	while (put_cycle(new, arena) == 0)
		new->pc++;
	return (*any_process);
}

void				inst_lfork(t_player *player, t_arena *arena)
{
	add_process_last(&player, arena);
}
