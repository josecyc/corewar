/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:22:26 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/11 09:55:23 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**  Op Code number 11; T_REG | T_DIR | T_IND, T_DIR | T_REG;
**  Take The value of the first Arg and write it to the cell of
**  the (PC + (arg[1] + arg[2] % IDX_MOD))
**  Change The carry --> 1 if 0 ; 0 if 1.
*/

static void		write_data(t_player *cur, t_arena *arena)
{
	int i;
	int adress;
	int data;
	int	res;

	res = cur->inst->args[1] + cur->inst->args[2];
	res %= IDX_MOD;
	cur->write_addr = get_addr_value(cur, (-cur->inst->size) + res);
	cur->write_bl = 1;
	adress = cur->write_addr;
	i = 24;
	data = cur->reg[cur->inst->args[0] - 1];
	while (i >= 0)
	{
		adress = (adress == MEM_SIZE) ? 0 : adress;
		arena->memory[adress] = (unsigned char)(data >> i);
		i -= 8;
		adress++;
	}
}

int				inst_sti2(t_player *cur, t_arena *arena, int *i, int *j)
{
	int		result;

	if ((cur->inst->ebyte >> *i & 3) == REG_CODE)
	{
		if (!valid_reg_int(cur, *j) && advance_proc_pc(&cur,
jump_next_op(cur->inst->op_code)))
			return (0);
		cur->inst->args[*j] = cur->reg[cur->inst->args[*j] - 1];
	}
	else if ((cur->inst->ebyte >> *i & 3) == IND_CODE)
	{
		result = get_addr_value(cur, (-cur->inst->size));
		cur->write_addr = get_addr_value(cur, \
		(cur->inst->args[*j] % IDX_MOD) + result);
		memory_to_int(&cur->inst->args[*j], arena, cur->write_addr, 4);
	}
	*i = *i - 2;
	return (1);
}

void			inst_sti(t_player *cur, t_arena *arena)
{
	int i;
	int j;

	j = 0;
	i = 4;
	if (!valid_reg_int(cur, 0))
	{
		advance_proc_pc(&cur, jump_next_op(cur->inst->op_code));
		return ;
	}
	while (i > 0 && ++j)
	{
		if (!inst_sti2(cur, arena, &i, &j))
			return ;
	}
	write_data(cur, arena);
}
