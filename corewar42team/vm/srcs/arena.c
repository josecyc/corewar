/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:48:07 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/02/02 09:45:22 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int		write_player(t_arena *arena, t_player *elem)
{
	int		i;
	int		pc_counter;

	i = 0;
	pc_counter = elem->pc;
	while (i < elem->prog_size)
	{
		arena->memory[pc_counter] = elem->prog[i++];
		ft_printf("[%d] = %.2x\n", pc_counter, arena->memory[pc_counter]);
		pc_counter++;
	}
	return (1);
}

static int		get_numplys(t_arena *arena, t_player **fplayer)
{
	int			num;
	t_player	*elem;

	num = 0;
	elem = *fplayer;
	while (elem)
	{
		elem = elem->next;
		num++;
	}
	ft_printf("num %d\n", num);
	arena->num_plys = num;
	if (num > 4)
		return (-1);
	return (num);
}

int		init_arena(t_arena *arena, t_player **fplayer)
{
	int			i;
	t_player	*elem;

	if (get_numplys(arena, fplayer) == -1)
		return (print_error(4, *fplayer, arena));
	i = arena->num_plys;
	elem = *fplayer;
	while (i > 0)
	{
		elem->pc = (i - 1) * (MEM_SIZE / arena->num_plys);
		ft_printf("%s starting at %d\n", elem->name, elem->pc);
		write_player(arena, elem);
		elem = elem->next;
		i--;
	}
	return (1);
}
