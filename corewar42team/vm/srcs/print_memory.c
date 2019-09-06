/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:01:01 by tholzheu          #+#    #+#             */
/*   Updated: 2019/09/05 13:01:40 by jcruz-y-         ###   ########.fr       */
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
	t_player	*cur = NULL;

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
		printf("- - - - - - - - -\n");
		printf("PLAYER NAME     = %s\n", cur->name);
		printf("PROCESS DEAD    = %d\n", cur->dead);
		printf("PLAYER NUM      = %d\n", cur->pnum);
		printf("PROG COUNTER    = %d\n", cur->pc);
		printf("LIVE            = %d\n", cur->life_bl);
		printf("CARRY           = %d\n", cur->carry);
		printf("- - - - - - - - -\n");
		printf("REGISTERS\n");
		printf("- - - - - - - - -\n");
		printf("R  1     = %d\n", cur->reg[0]);
		printf("R  2     = %d\n", cur->reg[1]);
		printf("R  3     = %d\n", cur->reg[2]);
		printf("R  4     = %d\n", cur->reg[3]);
		printf("R  5     = %d\n", cur->reg[4]);
		printf("R  6     = %d\n", cur->reg[5]);
		printf("R  7     = %d\n", cur->reg[6]);
		printf("R  8     = %d\n", cur->reg[7]);
		printf("R  9     = %d\n", cur->reg[8]);
		printf("R 10     = %d\n", cur->reg[9]);
		printf("R 11     = %d\n", cur->reg[10]);
		printf("R 12     = %d\n", cur->reg[11]);
		printf("R 13     = %d\n", cur->reg[12]);
		printf("R 14     = %d\n", cur->reg[13]);
		printf("R 15     = %d\n", cur->reg[14]);
		printf("R 16     = %d\n", cur->reg[15]);
		printf("- - - - - - - - -\n");
		printf("INSTRUCTION\n");
		printf("- - - - - - - - -\n");
		if (cur->inst->op_code > 0 && cur->inst->op_code < 17) 
			printf("MNEMONIC       = %s\n", op_tab[cur->inst->op_code - 1].mnemonic);
		printf("EXECUTE IN     = %d\n", cur->inst->counter);
		printf("OP_CODE        = %d\n", cur->inst->op_code);
		printf("E_BYTE         = %x\n", cur->inst->ebyte);
		printf("ARG 1 (hex)    = %x\n", cur->inst->args[0]);
		printf("ARG 1          = %d\n", cur->inst->args[0]);
		printf("ARG 2 (hex)    = %x\n", cur->inst->args[1]);
		printf("ARG 2          = %d\n", cur->inst->args[1]);
		printf("ARG 3 (hex)    = %x\n", cur->inst->args[2]);
		printf("ARG 3          = %d\n", cur->inst->args[2]);
		printf("SIZE           = %d\n", cur->inst->size);
		cur = cur->next;
	}
	printf("\033[0m");
}
