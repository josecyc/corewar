/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:23:21 by tholzheu          #+#    #+#             */
/*   Updated: 2019/08/29 20:04:25 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** Writes to the player arguments array which arguments are being used 
** indicated by an int
** returns the amount of bytes copied
*/

static int		memory_to_int(int *dest, t_arena *arena, int addr, int bytes) 
{
	int		i;

	i = 0;
	while (i++ < bytes)
	{
		if (addr == 4096)
			addr = 0;
		*dest <<= 8;
		*dest = ((int)arena->memory[addr++] & 255) | *dest;
	}
	return (bytes);
}

/*
** Translates encoding byte to arguments and 
** check_index are the particular instructions that have a DIR_CODE but actually
** have only 2 bytes.
*/

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

/*
** Saves instruction if:
** instruction has valid op_code
** ebyte is correct
** Must increase player counter if instruction is correct
** TO DO: Handle whenever circular memory and update player->pc
** TO DO? : not checking if ebyte is correct but doesn't match op
** invalid instruction?
** are arguments always valid? no there can be times when they have an incorrect opcode 
** incorrect encoding byte 
** incorrect register number 
** if op code is correct but register or encoding byte is incorrect do we execute wait the 
** cycles but not execute?
** 
*/

int				save_inst(t_player *player, t_arena *arena) 
{
	int		tmp_pc;

	tmp_pc = player->pc;
	// why char? because we only want to read 1 byte?
	player->inst->op_code = (char)arena->memory[tmp_pc];
	if (player->inst->op_code < 1 || player->inst->op_code < 16)
		return (-1);
	tmp_pc++;
	if (op_tab[player->inst->op_code - 1].encoding_byte == 1) //3 args?
	{
		player->inst->ebyte = (char)arena->memory[tmp_pc++];
		if (ebyte_to_args(player, arena, tmp_pc) == -1)
			return (-1);
	}
	else //1 arg?
	{
		if (check_index(player->inst->op_code - 1) == 1)
			tmp_pc += memory_to_int(&player->inst->args[0], arena, tmp_pc, 2);
		else
			tmp_pc += memory_to_int(&player->inst->args[0], arena, tmp_pc, 4);
	}
	player->pc = player->pc + tmp_pc;
	player->inst->counter = op_tab[player->inst->op_code - 1].num_cycles;
	return (1);
}
