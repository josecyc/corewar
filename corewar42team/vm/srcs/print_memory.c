/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:01:01 by tholzheu          #+#    #+#             */
/*   Updated: 2019/02/02 17:02:53 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_memory(char memory[MEM_SIZE])
{
	int		addr;

	addr = 0;
	printf("0x");
	while (addr < MEM_SIZE)
	{
		if (addr % 64 == 0)
			printf("%#.4x :", addr);
		printf(" %.2x", memory[addr] & 255);
		if ((addr + 1) % 64 == 0)
			printf("\n");
		addr++;
	}
}

void	print_info(t_arena *arena, t_player *fplayer)
{
	t_player	*cur;

	printf("\nARENA INFO\n");
	printf("NUM PLAYERS     = %d\n", arena->num_plys);
	printf("CYCLE_TO_DIE    = %d\n", arena->cycle_to_die);
	printf("TOTAL CYCLES    = %d\n", arena->total_cycles);
	printf("CYCLE COUNTER   = %d\n", arena->cycle_counter);
	printf("CHECKUP COUNTER = %d\n", arena->checkup_counter);
	printf("LIVE COUNTER    = %d\n", arena->live_counter);
	printf("LAST ALIVE      = %d\n\n", arena->last_alive);
	printf("FLAGS INFO\n");
	printf("DUMP FLAG       = %d\n", arena->flags->dump_bl);
	if (arena->flags->dump_bl)
		printf("DUMP CYCLES     = %d\n", arena->flags->dump_cycles);
	printf("INTERACTIVE     = %d\n", arena->flags->interactive);
	cur = fplayer;
	while (cur)
	{
		printf("\033[0;32m");
		printf("\nPLAYER NAME     = %s\n", cur->name);
		printf("DEAD            = %d\n", cur->dead);
		printf("PLAYER NUM      = %d\n", cur->pnum);
		printf("PROG COUNTER    = %d\n", cur->pc);
		printf("LIVE            = %d\n", cur->life_bl);
		printf("CARRY           = %d\n", cur->carry);
		printf("REGISTERS\n");
		printf("REGISTER  1     = %d\n", cur->reg[0]);
		printf("REGISTER  2     = %d\n", cur->reg[1]);
		printf("REGISTER  3    	= %d\n", cur->reg[2]);
		printf("REGISTER  4     = %d\n", cur->reg[3]);
		printf("REGISTER  5     = %d\n", cur->reg[4]);
		printf("REGISTER  6     = %d\n", cur->reg[5]);
		printf("REGISTER  7     = %d\n", cur->reg[6]);
		printf("REGISTER  8     = %d\n", cur->reg[7]);
		printf("REGISTER  9     = %d\n", cur->reg[8]);
		printf("REGISTER 10     = %d\n", cur->reg[9]);
		printf("REGISTER 11     = %d\n", cur->reg[10]);
		printf("REGISTER 12     = %d\n", cur->reg[11]);
		printf("REGISTER 13     = %d\n", cur->reg[12]);
		printf("REGISTER 14     = %d\n", cur->reg[13]);
		printf("REGISTER 15     = %d\n", cur->reg[14]);
		printf("REGISTER 16     = %d\n", cur->reg[15]);
		printf("INSTRUCTION\n");
		printf("INST COUNTER    = %d\n", cur->inst->counter);
		printf("INST OP_CODE    = %d\n", cur->inst->op_code);
		printf("INST ARG 1 (hex)= %x\n", cur->inst->args[0]);
		printf("INST ARG 1      = %d\n", cur->inst->args[0]);
		printf("INST ARG 2 (hex)= %x\n", cur->inst->args[1]);
		printf("INST ARG 2      = %d\n", cur->inst->args[1]);
		printf("INST ARG 3 (hex)= %x\n", cur->inst->args[2]);
		printf("INST ARG 3      = %d\n", cur->inst->args[2]);
		cur = cur->next;
	}
	printf("\033[0m");
}
