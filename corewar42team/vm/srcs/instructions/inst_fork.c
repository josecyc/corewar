/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:20:00 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/10 12:00:36 by jcruz-y-         ###   ########.fr       */
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

void		inst_fork(t_player **head, t_arena *arena, t_player *cur)
{
	t_player *new;
	t_player *tmp;
	
	tmp = (*head);
	new_process(&new, cur);
	advance_proc_pc(&new, (-cur->inst->size) + (cur->inst->args[0] % IDX_MOD));
	while (put_cycle(new, arena) == 0)
		new->pc++;
	(*head) = new;
	(*head)->next = tmp;
}
