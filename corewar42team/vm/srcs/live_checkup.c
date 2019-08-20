/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_checkup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 09:04:14 by tholzheu          #+#    #+#             */
/*   Updated: 2019/01/31 10:33:58 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	check_dead(t_player *players, t_arena *arena)
{
	t_player	*cur;
	int			count;

	cur = players;
	count = 0;
	while (cur)
	{
		if (cur->dead == 0 && cur->life_bl == 0 && ++count)
			cur->dead = 1; // insert sound for bonus
		cur = cur->next;
	}
	if (count == arena->num_plys)
		return (-1);
	arena->num_plys -= count;
	return (1);
}

int			live_checkup(t_player *players, t_arena *arena)
{
	arena->checkup_counter++;
	arena->cycle_counter = 0;
	if (check_dead(players, arena) == -1)
		return (-1);
	if (arena->live_counter >= NBR_LIVE || arena->checkup_counter == MAX_CHECKS)
	{
		arena->cycle_to_die -= CYCLE_DELTA;
		arena->checkup_counter = 0;
		arena->live_counter = 0;
	}
	return (1);
}
