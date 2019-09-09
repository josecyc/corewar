/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_lldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:22:18 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/09 14:01:44 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	inst_lldi(t_player *cur, t_arena *arena)
{
	int adress;
	int get_byte;
	int i;
	int args;

	args = -1;
	i = 6;
	while (i != 2 && ++args)
	{
		if ((cur->inst->ebyte >> i & 3) == REG_CODE)
			cur->inst->args[args] = cur->reg[cur->inst->args[args] - 1];
		else if ((cur->inst->ebyte >> i & 3) == DIR_CODE)
		{
			adress = get_addr_value(cur, (-cur->inst->size) + \
			(cur->inst->args[0] % IDX_MOD));
			memory_to_int(&get_byte, arena, adress, 2);
			cur->inst->args[args] = get_byte;
		}
		i -= 2;
	}
	adress = get_addr_value(cur, (-cur->inst->size) + \
	(cur->inst->args[0] + cur->inst->args[1]));
	memory_to_int(&get_byte, arena, adress, 4);
	cur->carry = (get_byte == 0) ? 1 : 0;
	cur->reg[cur->inst->args[2] - 1] = get_byte;
}
