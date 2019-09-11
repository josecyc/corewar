/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:23:21 by tholzheu          #+#    #+#             */
/*   Updated: 2019/09/10 17:35:01 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** Reads bytes from memory and writes the value to the player arguments array
** returns the amount of bytes copied
*/

int				memory_to_int(int *dest, t_arena *arena, \
		int src_addr, int bytes)
{
	int		i;
	short	res;

	i = 0;
	if (bytes == 2)
	{
		while (i++ < 2)
		{
			if (src_addr == MEM_SIZE)
				src_addr = 0;
			res <<= 8;
			res = ((int)arena->memory[src_addr++] & 255) | res;
		}
		*dest = res;
	}
	else
		while (i++ < bytes)
		{
			if (src_addr == MEM_SIZE)
				src_addr = 0;
			*dest <<= 8;
			*dest = ((int)arena->memory[src_addr++] & 255) | *dest;
		}
	return (bytes);
}

/*
** Translates encoding byte to arguments and
** check_index are the particular instructions that have a DIR_CODE but actually
** have only 2 bytes.
** checks also the validity of the encoding byte pairs and returns whenever
** they're invalid
*/

static int		ebyte_to_args2(t_player *player, t_arena *arena, \
		int *step, char e_pair)
{
	int result;

	result = (*step) + player->pc;
	if ((e_pair == IND_CODE && valid_ebyte(e_pair, player->valid_arg_type)) \
		|| (e_pair == DIR_CODE && g_op_tab[player->inst->op_code - 1].indexed))
		(*step) += memory_to_int(&player->inst->args[player->j], arena, \
			result, 2);
	else if (e_pair == DIR_CODE && valid_ebyte(e_pair,\
			player->valid_arg_type))
		(*step) += memory_to_int(&player->inst->args[player->j],\
		arena, result, 4);
	else
		return (0);
	return (1);
}

int				ebyte_to_args(t_player *player, t_arena *arena, int *step)
{
	int		i;
	char	e_pair;

	i = 6;
	player->j = -1;
	while (++player->j < g_op_tab[player->inst->op_code - 1].num_args)
	{
		e_pair = player->inst->ebyte >> i & 3;
		player->valid_arg_type = \
		g_op_tab[player->inst->op_code - 1].arg_types[player->j];
		if (e_pair == REG_CODE && valid_ebyte(e_pair, player->valid_arg_type) &&
		valid_reg(arena, player, *step))
		{
			player->inst->args[player->j] = \
			(int)arena->memory[player->pc + *step] & 255;
			(*step) += 1;
		}
		else if (ebyte_to_args2(player, arena, step, e_pair) == 1)
			;
		else
			return (-1);
		i -= 2;
	}
	return (1);
}

int				save_without_eb(t_player *player, t_arena *arena, int *step)
{
	if (g_op_tab[player->inst->op_code - 1].arg_types[0] == REG_CODE && \
			valid_reg(arena, player, *step))
		player->inst->args[0] = (int)arena->memory[player->pc + \
		(*step)++] & 255;
	else if (g_op_tab[player->inst->op_code - 1].indexed || \
			g_op_tab[player->inst->op_code - 1].arg_types[0] == IND_CODE)
		*step += memory_to_int(&player->inst->args[0], arena, player->pc + \
		*step, 2);
	else if (g_op_tab[player->inst->op_code - 1].arg_types[0] == DIR_CODE)
		*step += memory_to_int(&player->inst->args[0], arena, player->pc +\
		*step, 4);
	else
	{
		*step += jump_next_op(player->inst->op_code);
		advance_proc_pc(&player, *step);
		return (-1);
	}
	return (0);
}

int				save_inst(t_player *player, t_arena *arena)
{
	int		step;

	step = 0;
	if (player->inst->op_code > 16 || player->inst->op_code < 1)
		return (-1);
	advance_proc_pc(&player, 1);
	if (g_op_tab[player->inst->op_code - 1].encoding_byte == 1)
	{
		player->inst->ebyte = (char)arena->memory[player->pc];
		step++;
		if (ebyte_to_args(player, arena, &step) == -1)
		{
			step = 0;
			step += jump_next_op(player->inst->op_code);
			advance_proc_pc(&player, step);
			return (-1);
		}
	}
	else if (save_without_eb(player, arena, &step) == -1)
		return (-1);
	advance_proc_pc(&player, step);
	player->inst->size = step + 1;
	return (1);
}
