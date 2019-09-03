/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:38:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/03 11:35:23 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			get_addres_value(t_player *player, int step)
{
	if ((player->pc + step) >= MEM_SIZE)
		player->pc = (player->pc + step) % MEM_SIZE;
	else if ((player->pc + step) < 0)
		player->pc = MEM_SIZE - ((player->pc - step) % MEM_SIZE);
	else
		player->pc += step;	
	return (player->pc);
}

int		get_addr_value(int address, t_arena *arena)
{
    return (1);
}
