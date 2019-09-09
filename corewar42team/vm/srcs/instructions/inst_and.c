/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:10:29 by viduvern          #+#    #+#             */
/*   Updated: 2019/09/09 13:24:03 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		inst_and(t_player *cur, t_arena *arena)
{
	int			addrs;
	short		byte;
	int			args;
	int			i;

	args = 0;
	i = 6;
	while (i != 2)
	{
		if ((cur->inst->ebyte >> i & 3) == IND_CODE)
		{
			byte = (cur->inst->args[args] % IDX_MOD);
			addrs = get_addr_value(cur, (-cur->inst->size) + byte);
			memory_to_int(&cur->inst->args[args], arena, addrs, 4);
		}
		else if ((cur->inst->ebyte >> i & 3) == REG_CODE)
			cur->inst->args[args] = cur->reg[cur->inst->args[args] - 1];
		else
			;
		i -= 2;
		args++;
	}
	args = cur->inst->args[0] & cur->inst->args[1];
	cur->carry = (args == 0) ? 1 : 0;
	cur->reg[cur->inst->args[2] - 1] = args;
}
