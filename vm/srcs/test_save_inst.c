/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_save_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:01:14 by tholzheu          #+#    #+#             */
/*   Updated: 2019/01/31 08:47:06 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
#include <stdio.h>

void	init(t_player *player, t_arena *arena, t_inst *inst)
{
	inst->op_code = -1;
	inst->ebyte = 0;
	inst->counter = 0;
	inst->args[0] = 0;
	inst->args[1] = 0;
	inst->args[2] = 0;
	player->pc = 0;
	player->inst = inst;
	arena->memory[0] = 0x10;
	arena->memory[1] = 0x40;
	arena->memory[2] = 0xab;
	arena->memory[3] = 0xcd;
	arena->memory[4] = 0xef;
	arena->memory[5] = 0x00;
	arena->memory[6] = 0x01;
	arena->memory[7] = 0x02;
	arena->memory[8] = 0xf3;
	arena->memory[9] = 0x01;
	arena->memory[10] = 0x00;
	arena->memory[11] = 0x00;
	arena->memory[12] = 0x00;
	arena->memory[13] = 0x00;
	arena->memory[14] = 0x01;
	arena->memory[15] = 0x01;
	arena->memory[16] = 0x00;
	arena->memory[17] = 0x00;
	arena->memory[18] = 0x00;
	arena->memory[19] = 0x01;
	arena->memory[20] = 0x09;
	arena->memory[21] = 0xff;
	arena->memory[22] = 0xfb;
}

int		main(void)
{
	t_player	player;
	t_arena		arena;
	t_inst		inst;

	init(&player, &arena, &inst);
	if (save_inst(&player, &arena) == -1)
		return (0);
	printf("pc = %d\n", player.pc);
	printf("arg1 = %x\n", inst.args[0]);
	printf("arg2 = %x\n", inst.args[1]);
	printf("arg3 = %x\n", inst.args[2]);
	printf("op_code = %d\n", inst.op_code);
	printf("ebyte = %x\n", inst.ebyte);
	printf("counter = %d\n", inst.counter);
	return (0);
}
