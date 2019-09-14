/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:34:12 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/11 09:55:30 by jcruz-y-         ###   ########.fr       */
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

void		inst_dummy(t_player *p, t_arena *arena)
{
	return ;
}

void		inst_dummy2(t_player *p, t_arena *arena)
{
	return ;
}

static void	new_process(t_player **new, t_player *tmp)
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
	(*new)->proc_num = tmp->proc_num + 1;
	while (i < REG_NUMBER)
	{
		(*new)->reg[i] = tmp->reg[i];
		i++;
	}
}

void		inst_lfork(t_player **head, t_arena *arena, t_player *cur)
{
	t_player *new;
	t_player *tmp;

	tmp = (*head);
	new_process(&new, cur);
	advance_proc_pc(&new, (-cur->inst->size) + (cur->inst->args[0]));
	while (put_cycle(new, arena) == 0)
		new->pc++;
	(*head) = new;
	(*head)->next = tmp;
}
