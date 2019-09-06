/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:23:21 by tholzheu          #+#    #+#             */
/*   Updated: 2019/09/04 10:26:23 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** Advance player (process) pc
** taking into account circular memory
*/
int			advance_proc_pc(t_player **player, int step)
{
	if (((*player)->pc + step) >= MEM_SIZE)
		(*player)->pc = ((*player)->pc + step) % MEM_SIZE;
	else if (((*player)->pc + step) < 0)
		(*player)->pc = MEM_SIZE - (((*player)->pc - step) % MEM_SIZE);
	else
		(*player)->pc += step;	
	return (1);
}

/*
** Reads bytes from memory and writes the value to the player arguments array  
** returns the amount of bytes copied
*/

int		memory_to_int(int *dest, t_arena *arena, int src_addr, int bytes) 
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
	{
		while (i++ < bytes)
		{
			if (src_addr == MEM_SIZE)
				src_addr = 0;
			*dest <<= 8;
			*dest = ((int)arena->memory[src_addr++] & 255) | *dest;
		}
	}
	return (bytes);
}

/*
** Validates each ebyte pair against the valid arg types for the particular
** argument for the particular operation
*/

static int		valid_ebyte(char e_pair, char valid_arg_types)
{
	if ((e_pair & valid_arg_types) == e_pair)
		return (1);
	else
		return (0);
}

/*
** Takes arena, player and step to check a register byte in the arena
*/
static int		valid_reg(t_arena *arena, t_player *player, int step)
{
	if (arena->memory[player->pc + 1] > REG_NUMBER || arena->memory[player->pc + 1] <= 0)
	{
		advance_proc_pc(&player, step);
		return (-1);
	}
	else
		return (1);
}

/*
** Translates encoding byte to arguments and 
** check_index are the particular instructions that have a DIR_CODE but actually
** have only 2 bytes.
** checks also the validity of the encoding byte pairs and returns whenever 
** they're invalid
*/



static int		ebyte_to_args(t_player *player, t_arena *arena, int *step)
{
	int		i;
	int		j;
	char	e_pair;
	char	valid_arg_types;

	i = 6;
	j = 0;
	while (j < op_tab[player->inst->op_code - 1].num_args)
	{
		e_pair = player->inst->ebyte >> i & 3;
		valid_arg_types = op_tab[player->inst->op_code - 1].arg_types[j];
		if (e_pair == REG_CODE && valid_ebyte(e_pair, valid_arg_types) &&
		valid_reg(arena, player, *step)) //&& advance_proc_pc(&player, 1))  if invalid reg advance pc
		{
			player->inst->args[j] = (int)arena->memory[player->pc + *step] & 255;
			(*step) += 1;
		}
		else if (e_pair == IND_CODE && valid_ebyte(e_pair, valid_arg_types))
		{
			*step += memory_to_int(&player->inst->args[j], arena, player->pc + *step, 2);
		}
		else if (e_pair == DIR_CODE && op_tab[player->inst->op_code - 1].indexed &&
				 valid_ebyte(e_pair, valid_arg_types))
		{
			*step += memory_to_int(&player->inst->args[j], arena, player->pc + *step, 2);
		}
		else if (e_pair == DIR_CODE && valid_ebyte(e_pair, valid_arg_types))
		{
			*step += memory_to_int(&player->inst->args[j], arena, player->pc + *step, 4);
		}
		else
			return (-1);
		j++;
		i -= 2;
	}
	return (1);
}

/*
** Saves instruction if:
** instruction has valid op_code
** ebyte is correct
** Must increase player counter if instruction is correct
** TO DO: Handle whenever circular memory and update player->pc DONE
** TO DO? : not checking if ebyte is correct but doesn't match op DONE
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
	int		step;

	step = 0;
	player->inst->op_code = (char)arena->memory[player->pc]; // Char bc we only read 1 byte?
	if (player->inst->op_code < 1 || player->inst->op_code > 17)
		return (-1);
	advance_proc_pc(&player, 1);  //advance to encoding byte or first arg
	if (op_tab[player->inst->op_code - 1].encoding_byte == 1) 
	{
		player->inst->ebyte = (char)arena->memory[player->pc];
		step++;   //pc + step is now at arg1
		if (ebyte_to_args(player, arena, &step) == -1) //ebyte when more than 1 arg -> must advance step
		{
			advance_proc_pc(&player, step);
			return (-1);
		}
	}
	else //1 arg , check reg_num is valid
	{
		if (op_tab[player->inst->op_code - 1].arg_types[0] == REG_CODE && valid_reg(arena, player, step))
			player->inst->args[0] = (int)arena->memory[player->pc + step++] & 255;
		else if (op_tab[player->inst->op_code - 1].indexed || op_tab[player->inst->op_code - 1].arg_types[0] == IND_CODE)
			step += memory_to_int(&player->inst->args[0], arena, player->pc + step, 2);
		else if (op_tab[player->inst->op_code - 1].arg_types[0] == DIR_CODE)
			step += memory_to_int(&player->inst->args[0], arena, player->pc + step, 4);
		else
			return (-1); // this only happens when invalid reg num must advance one step
	}
	advance_proc_pc(&player, step);
	player->inst->size = op_tab[player->inst->op_code - 1].encoding_byte ? step + 1 : step;
	player->inst->counter = op_tab[player->inst->op_code - 1].num_cycles - 1;
	//print_info(arena, player);
	return (1);
}
