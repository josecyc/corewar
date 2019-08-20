/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:23:21 by tholzheu          #+#    #+#             */
/*   Updated: 2019/02/04 10:51:49 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int		ebyte_to_args(t_player *player, t_arena *arena, int tmp_pc)
{
	int		i;
	int		j;
	int		n;
	char	tmp;

	i = 6;
	n = op_tab[player->inst->op_code - 1].num_args;
	j = 0;
	while (j < n)
	{
		tmp = player->inst->ebyte >> i & 3;
		if (tmp == REG_CODE)
			player->inst->args[j++] = (int)arena->memory[tmp_pc++] & 255;
		else if (tmp == IND_CODE)
			tmp_pc += memory_to_int(&player->inst->args[j++], arena, tmp_pc, 2);
		else if (tmp == DIR_CODE && check_index(player->inst->op_code) == 1)
			tmp_pc += memory_to_int(&player->inst->args[j++], arena, tmp_pc, 2);
		else if (tmp == DIR_CODE)
			tmp_pc += memory_to_int(&player->inst->args[j++], arena, tmp_pc, 4);
		else
			return (-1);
		i -= 2;
	}
	return (1);
}

int				save_inst(t_player *player, t_arena *arena) // not checking if ebyte is correct but doesn't match op
{
	int		tmp_pc;

	tmp_pc = player->pc;
	player->inst->op_code = (char)arena->memory[tmp_pc];
	tmp_pc++;
	if (op_tab[player->inst->op_code - 1].encoding_byte == 1)
	{
		player->inst->ebyte = (char)arena->memory[tmp_pc++];
		if (ebyte_to_args(player, arena, tmp_pc) == -1)
			return (-1);
	}
	else
	{
		if (check_index(player->inst->op_code - 1) == 1)
			tmp_pc += memory_to_int(&player->inst->args[0], arena, tmp_pc, 2);
		else
			tmp_pc += memory_to_int(&player->inst->args[0], arena, tmp_pc, 4);
	}
	player->inst->counter = op_tab[player->inst->op_code - 1].num_cycles;
	return (1);
}
