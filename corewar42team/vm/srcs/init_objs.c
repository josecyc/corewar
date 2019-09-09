/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:30:51 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/09 13:14:36 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	init_arena_ob(t_arena *arena, int argc, char **argv)
{
	int	i;

	i = 0;
	arena->argc = argc;
	arena->argv = argv;
	while (i < MEM_SIZE)
	{
		arena->memory[i] = 0;
		i++;
	}
	if (!(arena->flags = (t_flag*)malloc(sizeof(t_flag))))
		exit(1);
	arena->num_plys = 0;
	arena->cycle_to_die = CYCLE_TO_DIE;
	arena->total_cycles = 0;
	arena->cycle_counter = 0;
	arena->checkup_counter = 0;
	arena->live_counter = 0;
	arena->flags->interactive = 0;
	arena->flags->dump_bl = 0;
	arena->flags->dump_cycles = 0;
	arena->last_alive = 0;
}
