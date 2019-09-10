/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:38:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/10 00:10:33 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			get_addr_value(t_player *player, int step)
{
	int		pc;

	pc = 0;
	if ((player->pc + step) >= MEM_SIZE)
		pc = (player->pc + step) % MEM_SIZE;
	else if ((player->pc + step) < 0)
		pc = MEM_SIZE + ((player->pc + step) % MEM_SIZE);
	else
		pc = player->pc + step;
	return (pc);
}

/*
** Validates each ebyte pair against the valid arg types for the particular
** argument for the particular operation
** 11 IND_CODE (e_pair) 100 i.e. 4 == T_IND, indirect arg type
*/

int			valid_ebyte(char e_pair, char valid_arg_types)
{
	if ((e_pair & valid_arg_types) == e_pair || \
		(e_pair == 3 && ((valid_arg_types & 4) == 4)))
		return (1);
	else
		return (-1);
}

/*
** Takes arena, player and step to check a register byte in the arena
*/

int			valid_reg(t_arena *arena, t_player *player, int step)
{
	if (arena->memory[player->pc + step] > REG_NUMBER || \
		arena->memory[player->pc + step] <= 0)
	{
		return (-1);
	}
	else
		return (1);
}

int			valid_reg_int(t_player *cur, int num)
{
	if (num == 4)
	{
		if (cur->inst->args[0] <= REG_NUMBER && cur->inst->args[0] > 0 &&
		cur->inst->args[1] <= REG_NUMBER && cur->inst->args[1] > 0 &&
		cur->inst->args[2] <= REG_NUMBER && cur->inst->args[2] > 0)
			return (1);
	}	
	else if (num == 0 && cur->inst->args[0] <= REG_NUMBER &&\
	cur->inst->args[0] > 0)
		return (1);
	else if (num == 1 && cur->inst->args[1] <= REG_NUMBER &&\
	cur->inst->args[1] > 0)
		return (1);
	else if (num == 2 && cur->inst->args[2] <= REG_NUMBER &&\
	cur->inst->args[2] > 0)
		return (1);
	return (0);
}