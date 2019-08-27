/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:58:22 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/08/26 20:27:08 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int		get_args(t_arena *arena, t_player **fplayer)
{
	int i;

	i = 1;
	while (arena->argv[i])
	{
		if (get_flags(arena, &i, fplayer) == -1)
			return(-1);
		if(get_player(arena, fplayer, &i) == -1)
				return (-1);
		else
			i++;
	}
	return (1);
}

static int		init_state(t_arena *arena, t_player **fplayer)
{
	if (arena->argc == 1)
		return (print_error(7, *fplayer, arena));
	if (get_args(arena, fplayer) == -1)
		return (-1);
	ft_printf("\n\ninitializing ARENA\n\nfplayer->next->name %s\n", (*fplayer)->name);
	if (init_arena(arena, fplayer) == -1)
		return (-1);
	return (1);
}

int		main(int argc, char **argv)
{
	t_arena		arena;
	t_player	*fplayer;

	init_arena_ob(&arena, argc, argv);
	fplayer = NULL;
	if (init_state(&arena, &fplayer) == -1)
	{
//	system("leaks corewar");
		return (-1);
	}
	loop(fplayer, &arena);
	system("leaks corewar");
	return (0);
}
