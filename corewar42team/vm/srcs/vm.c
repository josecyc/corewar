/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:58:22 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/09/10 19:12:58 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int		get_args(t_arena *arena, t_player **fplayer)
{
	int i;

	i = 1;
	while (i < arena->argc)
	{
		while (i < arena->argc && (ft_strcmp(arena->argv[i], "-dump") == 0 ||
		ft_strcmp(arena->argv[i], "-i") == 0))
			if (get_flags(arena, &i, fplayer) == -1)
				return (-1);
		if (i < arena->argc && get_player(arena, fplayer, &i) == -1)
			return (-1);
		i++;
	}
	if (*fplayer == NULL)
		return (print_error2(1, *fplayer, arena));
	return (1);
}

static int		init_state(t_arena *arena, t_player **fplayer)
{
	if (arena->argc == 1)
		return (print_error(7, *fplayer, arena));
	if (get_args(arena, fplayer) == -1)
		return (-1);
	if (init_arena(arena, fplayer) == -1)
		return (-1);
	return (1);
}

int				main(int argc, char **argv)
{
	t_arena		arena;
	t_player	*fplayer;
	t_window	win;

	init_arena_ob(&arena, argc, argv);
	fplayer = NULL;
	if (init_state(&arena, &fplayer) == -1)
		return (-1);
	loop(fplayer, &arena);
	if ((!arena.flags->interactive && !arena.flags->dump_bl) ||
	(arena.flags->dump_bl && arena.total_cycles < arena.flags->dump_cycles))
		announce_winner(fplayer, &arena);
	return (0);
}
