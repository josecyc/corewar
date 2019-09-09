/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:20:00 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/09 14:27:54 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** op_code 12
** arg1 DIR -> indexed
** Fork creates a new process which inherits the same REG_NUM registers and
** contents of the parent and begins execution (pc address) where the first
** argument indicates
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
	advance_proc_pc(&new, (-tmp->inst->size) + (tmp->inst->args[0] % IDX_MOD));
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = new;
	new->next = tmp;
	while (put_cycle(new, arena) == 0)
		new->pc++;
	return (*any_process);
}

void				inst_fork(t_player *player, t_arena *arena)
{
	add_process_last(&player, arena);
}
