/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:38:45 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/04 16:27:12 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			get_addr_value(t_player *player, int step)
{
	int		pc;

	pc = 0;
	if ((player->pc + step) >= MEM_SIZE)
		pc = (player->pc + step) % MEM_SIZE;
	else if ((player->pc + step) < 0)
		pc = MEM_SIZE + ((player->pc + step) % MEM_SIZE);
	else
		pc = player->pc + step;	
	return (pc);
}
